#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include "token.h"
#include "table.h"
#include "ast.h"

typedef vec(struct token) TokenVector;

char const *
parse_error(Ty *ty);

struct statement **
parse(Ty *ty, char const *source, char const *file);

bool
parse_ex(
        Ty *,
        char const *source,
        char const *file,
        struct statement ***prog_out,
        Location *err_loc,
        TokenVector *tok_out
);

Token
parse_get_token(Ty *ty, int i);

struct value
parse_get_expr(Ty *ty, int prec, bool resolve, bool want_raw);

struct value
parse_get_stmt(Ty *ty, int prec, bool want_raw);

void
parse_next(Ty *ty);

noreturn void
parse_fail(Ty *ty, char const *s, size_t n);

void
parse_sync_lex(Ty *ty);

void
make_with(Ty *ty, struct expression *e, statement_vector defs, struct statement *body);

char *
gensym(Ty *ty);

#endif
