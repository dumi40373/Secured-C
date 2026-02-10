/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H
typedef struct linked_lists_s {
    char *key;
    char *value;
    struct linked_lists_s *next;
} linked_lists_t;
typedef struct hashtable_s {
    int len;
    int (*hash_func)(char *, int);
    linked_lists_t **list;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// my_lib
int my_strlen(char const *str);
int my_nbrlen(long int nbr);
char *my_strdup(const char *str);
int my_str_in_ascii(char *str);
int my_pow(int nbr, int expo);
int my_strcmp(char const *s1, char const *s2);
char *int_to_string(int nbr);
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(long int nb);
#endif /* HASHTABLE_H */
