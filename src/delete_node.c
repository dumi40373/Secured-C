/*
** EPITECH PROJECT, 2026
** secured
** File description:
** delete node
*/

#include "../include/hashtable.h"

static void free_node(linked_lists_t *node)
{
    free(node->key);
    free(node->value);
    free(node);
}

static int delete_head_if_match(hashtable_t *ht, linked_lists_t *cur,
    int index, int hashed)
{
    if (ht->hash_func(cur->key, ht->len) == hashed) {
        ht->list[index] = cur->next;
        free_node(cur);
        return 1;
    }
    return 0;
}

static int error_handling_del(hashtable_t *ht, char *key)
{
    if (!ht || !key || !ht->list || my_strlen(key) <= 0)
        return 1;
    return 0;
}

static linked_lists_t *update_values_del(int *hashed,
    int *index, hashtable_t *ht, char *key)
{
    linked_lists_t *cur = NULL;

    *hashed = ht->hash_func(key, ht->len);
    *index = *hashed % ht->len;
    cur = ht->list[*index];
    return cur;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int index = 0;
    linked_lists_t *prev = NULL;
    linked_lists_t *cur = NULL;

    if (error_handling_del(ht, key))
        return 84;
    cur = update_values_del(&hashed, &index, ht, key);
    if (delete_head_if_match(ht, cur, index, hashed))
        return 0;
    prev = cur;
    for (cur = cur->next; cur; cur = cur->next) {
        if (ht->hash_func(cur->key, ht->len) == hashed){
            prev->next = cur->next;
            free_node(cur);
            return 0;
        }
        prev = cur;
    }
    return 84;
}
