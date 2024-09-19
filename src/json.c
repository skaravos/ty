#include <setjmp.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <utf8proc.h>

#include "test.h"
#include "value.h"
#include "dict.h"
#include "util.h"
#include "table.h"
#include "class.h"
#include "vec.h"
#include "vm.h"

#define KW_DELIM(c) (strchr(" \n}],", c) != NULL)
#define FAIL longjmp(jb, 1)

static _Thread_local jmp_buf jb;
static _Thread_local char const *json;
static _Thread_local int len;

typedef vec(char) str;

static _Thread_local vec(void const *) Visiting;

inline static char
peek(void)
{
        if (len <= 0)
                return '\0';

        return *json;
}

inline static char
next(void)
{
        if (len <= 0)
                return '\0';
        --len;
        return *json++;
}

static Value
value(Ty *ty);

inline static void
space(void)
{
        while (isspace(peek())) next();
}

static struct value
number(void)
{
        char numbuf[512];
        char const *num = json;
        bool integral = true;

        if (peek() == '-')
                next();

        if (!isdigit(peek()))
                FAIL;

        while (isdigit(peek()))
                next();

        if (peek() == '.') {
                integral = false;
                next();
                if (!isdigit(peek()))
                        FAIL;
                while (isdigit(peek()))
                        next();
        }

        if (peek() == 'e' || peek() == 'E') {
                integral = false;
                next();
                if (peek() == '-' || peek() == '+')
                        next();
                if (!isdigit(peek()))
                        FAIL;
                while (isdigit(peek()))
                        next();
        }

        int n = min(json - num, sizeof numbuf - 1);
        memcpy(numbuf, num, n);
        numbuf[n] = '\0';

        struct value result;

        errno = 0;
        if (integral)
                result = INTEGER(strtoimax(num, NULL, 10));
        else
                result = REAL(strtod(num, NULL));

        if (errno != 0)
                FAIL;

        return result;
}

static struct value
null(void)
{
        if (strncmp(json, "null", 4) != 0)
                FAIL;

        if (!KW_DELIM(json[4]))
                FAIL;

        json += 4;
        len -= 4;

        return NIL;
}

static struct value
jtrue(void)
{
        if (strncmp(json, "true", 4) != 0)
                FAIL;

        if (!KW_DELIM(json[4]))
                FAIL;

        json += 4;
        len -= 4;

        return BOOLEAN(true);
}

static struct value
jfalse(void)
{
        if (strncmp(json, "false", 5) != 0)
                FAIL;

        if (!KW_DELIM(json[5]))
                FAIL;

        json += 5;
        len -= 5;

        return BOOLEAN(false);
}

static struct value
string(Ty *ty)
{
        if (next() != '"')
                FAIL;

        vec(char) str;
        vec_init(str);

        char b[8] = {0};
        unsigned hex;
        utf8proc_ssize_t n;

        while (peek() != '\0' && peek() != '"') {
                if (peek() == '\\') switch (next(), next()) {
                case 't':  xvP(str, '\t'); break;
                case 'f':  xvP(str, '\f'); break;
                case 'n':  xvP(str, '\n'); break;
                case 'r':  xvP(str, '\r'); break;
                case 'b':  xvP(str, '\b'); break;
                case '"':  xvP(str, '"');  break;
                case '/':  xvP(str, '/');  break;
                case '\\': xvP(str, '\\'); break;
                case 'x':
                        b[0] = next();
                        b[1] = next();
                        b[2] = '\0';
                        if (sscanf(b, "%X", &hex) != 1) {
                                FAIL;
                        }
                        xvP(str, (char)hex);
                        break;
                case 'u':
                        b[0] = isxdigit(peek()) ? next() : '\0';
                        b[1] = isxdigit(peek()) ? next() : '\0';
                        b[2] = isxdigit(peek()) ? next() : '\0';
                        b[3] = isxdigit(peek()) ? next() : '\0';
                        b[4] = '\0';
                        if (sscanf(b, "%x", &hex) != 1) {
                                FAIL;
                        }
                        n = utf8proc_encode_char(hex, b);
                        xvPn(str, b, n);
                        break;
                } else xvP(str, next());
        }

        if (next() != '"')
                FAIL;

        n = str.count;

        if (n == 0)
                return STRING_NOGC(NULL, 0);

        char *s = value_string_alloc(ty, n);
        memcpy(s, str.items, n);

        free(str.items);

        return STRING(s, n);
}

static struct value
array(Ty *ty)
{
        if (next() != '[')
                FAIL;

        struct array *a = vA();

        while (peek() != '\0' && peek() != ']') {
                xvP(*a, value(ty));
                space();
                if (peek() != ']' && next() != ',')
                        FAIL;
        }

        if (next() != ']')
                FAIL;

        return ARRAY(a);
}

static struct value
object(Ty *ty)
{
        if (next() != '{')
                FAIL;

        struct dict *obj = dict_new(ty);

        while (peek() != '\0' && peek() != '}') {
                space();
                struct value key = string(ty);
                space();
                if (next() != ':')
                        FAIL;
                struct value val = value(ty);
                dict_put_value(ty, obj, key, val);
                space();
                if (peek() != '}' && next() != ',')
                        FAIL;
        }

        if (next() != '}')
                FAIL;

        return DICT(obj);
}

static struct value
value(Ty *ty)
{
        space();

        switch (peek()) {
        case '{': return object(ty);
        case '[': return array(ty);
        case '"': return string(ty);
        case 'n': return null();
        case 't': return jtrue();
        case 'f': return jfalse();
        case '-': case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
                return number();
        default: FAIL;
        }
}

inline static bool
visiting(void const *p)
{
        for (int i = 0; i < Visiting.count; ++i) {
                if (Visiting.items[i] == p) {
                        return true;
                }
        }

        return false;
}

inline static bool
try_visit(void const *p)
{
        if (visiting(p)) {
                return false;
        } else {
                xvP(Visiting, p);
                return true;
        }
}

static bool
encode(Ty *ty, Value const *v, str *out)
{
        switch (v->type & ~VALUE_TAGGED) {
        case VALUE_NIL:
                xvPn(*out, "null", 4);
                break;
        case VALUE_STRING:
                xvP(*out, '"');
                for (int i = 0; i < v->bytes; ++i) {
                        switch (v->string[i]) {
                        case '\t':
                                xvP(*out, '\\');
                                xvP(*out, 't');
                                break;
                        case '\n':
                                xvP(*out, '\\');
                                xvP(*out, 'n');
                                break;
                        case '\\':
                        case '"':
                                xvP(*out, '\\');
                        default:
                                xvP(*out, v->string[i]);
                                break;
                        }
                }
                xvP(*out, '"');
                break;
        case VALUE_BOOLEAN:
                if (v->boolean)
                        xvPn(*out, "true", 4);
                else
                        xvPn(*out, "false", 5);
                break;
        case VALUE_INTEGER:
                xvR(*out, out->count + 64);
                out->count += snprintf(out->items + out->count, 64, "%"PRIiMAX, v->integer);
                break;
        case VALUE_REAL:
                xvR(*out, out->count + 64);
                out->count += snprintf(out->items + out->count, 64, "%g", v->real);
                break;
        case VALUE_ARRAY:
                xvP(*out, '[');
                if (!try_visit(v->array))
                        return false;
                for (int i = 0; i < v->array->count; ++i) {
                        if (!encode(ty, &v->array->items[i], out))
                                return false;
                        if (i + 1 < v->array->count)
                                xvP(*out, ',');
                }
                vvX(Visiting);
                xvP(*out, ']');
                break;
        case VALUE_DICT:
                xvP(*out, '{');
                int last = -1;
                for (int i = 0; i < v->dict->size; ++i)
                        if (v->dict->keys[i].type == VALUE_STRING)
                                last = i;
                if (!try_visit(v->dict))
                        return false;
                for (int i = 0; i < v->dict->size; ++i) {
                        if (v->dict->keys[i].type != VALUE_STRING)
                                continue;
                        if (!encode(ty, &v->dict->keys[i], out))
                                return false;
                        xvP(*out, ':');
                        if (!encode(ty, &v->dict->values[i], out))
                                return false;
                        if (i != last)
                                xvP(*out, ',');
                }
                vvX(Visiting);
                xvP(*out, '}');
                break;
        case VALUE_OBJECT:
        {
                if (!try_visit(v->object))
                        return false;

                struct value *vp = class_method(ty, v->class, "__json__");

                if (vp != NULL) {
                        struct value method = METHOD("__json__", vp, v);
                        struct value s = vm_eval_function(ty, NULL, &method, NULL);
                        if (s.type == VALUE_STRING) {
                                gP(&s);
                                xvPn(*out, s.string, s.bytes);
                                gX();
                        } else {
                                return encode(ty, &s, out);
                        }
                } else {
                        xvP(*out, '{');
                        for (int i = 0; i < TABLE_SIZE; ++i) {
                                for (int j = 0; j < v->object->buckets[i].names.count; ++j) {
                                        xvP(*out, '"');
                                        char const *name = v->object->buckets[i].names.items[j];
                                        xvPn(*out, name, strlen(name));
                                        xvP(*out, '"');
                                        xvP(*out, ':');
                                        if (!encode(ty, &v->object->buckets[i].values.items[j], out))
                                                return false;
                                        xvP(*out, ',');
                                }
                        }
                        vvX(Visiting);
                        if (*vvL(*out) == ',')
                                *vvL(*out) = '}';
                        else
                                xvP(*out, '}');
                }
                break;
        }
        case VALUE_TUPLE:
                xvP(*out, '{');
                if (!try_visit(v->items))
                        return false;
                for (int i = 0; i < v->count; ++i) {
                        xvP(*out, '"');
                        if (v->names != NULL && v->names[i] != NULL) {
                                xvPn(*out, v->names[i], strlen(v->names[i]));
                        } else {
                                char b[32];
                                snprintf(b, sizeof b - 1, "%d", i);
                                xvPn(*out, b, strlen(b));
                        }
                        xvP(*out, '"');
                        xvP(*out, ':');
                        if (!encode(ty, &v->items[i], out)) {
                                return false;
                        }
                        xvP(*out, ',');
                }
                vvX(Visiting);
                if (*vvL(*out) == ',') {
                        *vvL(*out) = '}';
                } else {
                        xvP(*out, '}');
                }
                break;
        case VALUE_BLOB:
                xvP(*out, '"');
                for (int i = 0; i < v->blob->count; ++i) {
                        char b[3];
                        snprintf(b, sizeof b, "%.2X", (unsigned)v->blob->items[i]);
                        xvP(*out, '\\');
                        xvP(*out, 'x');
                        xvP(*out, b[0]);
                        xvP(*out, b[1]);
                }
                xvP(*out, '"');
                break;
        default:
                return false;

        }

        return true;
}

struct value
json_parse(Ty *ty, char const *s, int n)
{
        json = s;
        len = n;

        GC_STOP();

        if (setjmp(jb) != 0) {
                GC_RESUME();
                return NIL;
        }

        struct value v = value(ty);
        space();

        if (peek() != '\0')
                v = NIL;

        GC_RESUME();

        return v;
}

struct value
json_encode(Ty *ty, struct value const *v)
{
        str s;
        vec_init(s);

        struct value r = NIL;

        Visiting.count = 0;

        if (encode(ty, v, &s)) {
                r = vSc(s.items, s.count);
                free(s.items);
        }

        return r;
}
