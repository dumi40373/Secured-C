/*
** EPITECH PROJECT, 2026
** secured
** File description:
** handle_table
*/

#include "../include/hashtable.h"

static int comparing_insert(linked_lists_t *cur, char *key,
    char *value)
{
    char *dup;

    if (my_strcmp(cur->key, key)) {
        dup = my_strdup(value);
        if (!dup)
            return 84;
        free(cur->value);
        cur->value = dup;
        return 0;
    }
    return 1;
}

static int is_already_node(hashtable_t *ht, int index, char *key, char *value)
{
    linked_lists_t *cur = ht->list[index];
    int error_handling = 0;

    for (; cur; cur = cur->next) {
        error_handling = comparing_insert(cur, key, value);
        if (error_handling != 1)
            return error_handling;
    }
    return 1;
}

static int update_insert_value(char *key, char *value,
    hashtable_t *ht, int index)
{
    linked_lists_t *node = malloc(sizeof(linked_lists_t));

    if (!node)
        return 84;
    node->key = my_strdup(key);
    node->value = my_strdup(value);
    if (!node->key || !node->value) {
        free(node->key);
        free(node->value);
        free(node);
        return 84;
    }
    node->next = ht->list[index];
    ht->list[index] = node;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed = 0;
    int index = 0;
    int already_node = 0;

    if (!ht || !ht->list || !ht->hash_func || ht->len <= 0 || !key || !value)
        return 84;
    hashed = ht->hash_func(key, ht->len);
    index = hashed % ht->len;
    if (index < 0)
        index *= -1;
    already_node = is_already_node(ht, index, key, value);
    if (already_node != 1)
        return already_node;
    if (update_insert_value(key, value, ht, index) != 0)
        return 84;
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    linked_lists_t **list = NULL;
    linked_lists_t *cur = NULL;

    if (!ht)
        return;
    list = ht->list;
    for (int i = 0; i < ht->len; i++) {
        cur = list[i];
        my_putchar('[');
        my_putnbr(i);
        my_putstr("]:\n");
        for (; cur; cur = cur->next) {
            my_putstr("> ");
            my_putnbr(ht->hash_func(cur->key, ht->len));
            my_putstr(" - ");
            my_putstr(cur->value);
            my_putchar('\n');
        }
    }
}

static char *list_loop(linked_lists_t *cur, char *key)
{
    for (; cur; cur = cur->next) {
        if (my_strcmp(cur->key, key))
            return cur->value;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    linked_lists_t *cur;
    char *find_value;

    if (!ht || !ht->list || !key)
        return NULL;
    for (int i = 0; i < ht->len; i++) {
        cur = ht->list[i];
        find_value = list_loop(cur, key);
        if (find_value)
            return find_value;
    }
    return NULL;
}
