/*
** EPITECH PROJECT, 2026
** secured
** File description:
** my string utils
*/

#include "../include/hashtable.h"

int my_strlen(char const *str)
{
    int x = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++){
        x++;
    }
    return x;
}

char *my_strdup(const char *str)
{
    char *res;

    if (!str)
        return NULL;
    res = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!res)
        return NULL;
    for (int i = 0; str[i]; i++)
        res[i] = str[i];
    res[my_strlen(str)] = '\0';
    return res;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) == my_strlen(s2)) {
        for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    }
    if (i == my_strlen(s1))
        return 1;
    return 0;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putnbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}
