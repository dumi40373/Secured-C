/*
** EPITECH PROJECT, 2026
** secured
** File description:
** hashtable
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (!ht || len == 0)
        return NULL;
    ht->len = len;
    ht->hash_func = hash;
    ht->list = malloc(sizeof(linked_lists_t *) * len);
    if (!ht->list) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        ht->list[i] = NULL;
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    linked_lists_t *cur;
    linked_lists_t *tmp;

    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++) {
        cur = ht->list[i];
        for (; cur; cur = tmp) {
            tmp = cur->next;
            free(cur->key);
            free(cur->value);
            free(cur);
        }
    }
    free(ht->list);
    free(ht);
}
