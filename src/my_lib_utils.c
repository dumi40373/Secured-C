/*
** EPITECH PROJECT, 2026
** secured
** File description:
** lib_utils
*/

#include "../include/hashtable.h"

int my_nbrlen(long int nbr)
{
    long int cmpt = 0;

    if (nbr == 0)
        return 1;
    if (nbr < 0)
        nbr = -nbr;
    while (nbr != 0) {
        nbr = nbr / 10;
        cmpt++;
    }
    return cmpt;
}

char *int_to_string(int nbr)
{
    int negative = (nbr < 0);
    int len = my_nbrlen(nbr);
    char *str = malloc(len + negative + 1);

    str[len + negative] = '\0';
    if (nbr < 0)
        nbr = -nbr;
    for (int i = len + negative - 1; i >= 0; i--) {
        str[i] = '0' + (nbr % 10);
        nbr /= 10;
    }
    if (negative)
        str[0] = '-';
    return str;
}

int my_pow(int nbr, int expo)
{
    int result = nbr * nbr;

    if (expo == 1)
        return nbr;
    if (expo == 0)
        return 1;
    for (int i = 2; i < expo; i++){
        result = result * nbr;
    }
    return result;
}

int my_str_in_ascii(char *str)
{
    int result = 0;

    for (int i= 0; str[i] != '\0'; i++)
        result += (int)str[i];
    return result;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
