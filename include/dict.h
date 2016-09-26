#ifndef DICT_H_INCLUDED
#define DICT_H_INCLUDED

enum {
        DICT_NUM_BUCKETS = 128,
};

#include "value.h"

struct dict *
dict_new(void);

size_t
dict_item_count(struct dict const *obj);

struct value *
dict_get_value(struct dict const *obj, struct value const *key);

void
dict_put_value(struct dict *obj, struct value key, struct value value);

struct value *
dict_get_member(struct dict const *obj, char const *key);

void
dict_put_member(struct dict *obj, char const *key, struct value value);

struct value *
dict_put_key_if_not_exists(struct dict *obj, struct value key);

struct value *
dict_put_member_if_not_exists(struct dict *obj, char const *member);

void
dict_mark(struct dict *obj);

void
dict_free(struct dict *obj);

#endif