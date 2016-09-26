#ifndef GC_H_INCLUDED
#define GC_H_INCLUDED

#include <stddef.h>

#include "vec.h"

#define ALLOC_OF(p) ((struct alloc *)(((char *)(p)) - offsetof(struct alloc, data)))

#define MARKED(v) ((ALLOC_OF(v))->mark & GC_MARK)
#define MARK(v)   ((ALLOC_OF(v))->mark |= GC_MARK)
#define UNMARK(v) ((ALLOC_OF(v))->mark &= GC_MARK)
#define NOGC(v)   ((ALLOC_OF(v))->mark |= GC_HARD)
#define OKGC(v)   ((ALLOC_OF(v))->mark &= ~GC_HARD)

extern bool GC_ENABLED;

struct alloc {
        union {
                struct {
                        char type;
                        char mark;
                };
                void const * restrict padding;
        };
        char data[];
};

enum {
        GC_STRING,
        GC_ARRAY,
        GC_OBJECT,
        GC_DICT,
        GC_VARIABLE,
        GC_REF_VECTOR,
        GC_BLOB,
        GC_VALUE,
};

enum {
        GC_NONE = 1 << 0,
        GC_MARK = 1 << 1,
        GC_HARD = 1 << 2,
};

void *
gc_alloc(size_t n);

void *
gc_alloc_object(size_t n, char type);

void
gc_register(void *p);

void
gc_push(struct value *v);

void
gc_pop(void);

void
gc_clear_root_set(void);

inline static void *
gc_alloc_unregistered(size_t n, char type)
{
        struct alloc *a = alloc(sizeof *a + n);

        a->mark = GC_NONE;
        a->type = type;

        return a->data;
}

inline static void
gc_disable(void)
{
        GC_ENABLED = false;
}

inline static void
gc_enable(void)
{
        GC_ENABLED = true;
}

#endif
