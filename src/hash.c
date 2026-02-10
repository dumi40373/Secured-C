/*
** EPITECH PROJECT, 2026
** secured
** File description:
** main.c
*/

#include "../include/hashtable.h"

int error_handling(char *key)
{
    if (!key)
        return 1;
    return 0;
}

int calc_hash(char *key)
{
    int hash = my_str_in_ascii(key);

    for (int i = 0; key[i] != '\0'; i++)
        hash = hash ^ (((hash << 2) + hash) + (int)key[i]);
    if (hash < 0)
        hash = -hash;
    return (hash >> 1) ^ hash << 2;
}

int hash(char *key, int len)
{
    if (error_handling(key))
        return 84;
    return calc_hash(key);
}
