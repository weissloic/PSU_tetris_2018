/*
** EPITECH PROJECT, 2019
** useful functions
** File description:
** functions
*/
#include "../include/my.h"


unsigned int my_atoui(char *str)
{
    unsigned int res = 0;
    int i = 0;

    while ((str[i] >= '0') && (str[i] <= '9')){
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    return (res);
}

int my_atoi(char *str)
{
    int neg;
    int number = 0;
    int number_two = 0;

    neg = 0;
    while (*str == '-' || *str == '+') {
        if (*str == '-')
            neg = !neg;
        str++;
    }

    if (neg)
        return (number = (-1 * my_atoui(str)));
    else
        return (number_two = my_atoui(str));
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i <= n; i++) {
        dest[i] = src[i];
        if (n == i)
            dest[n] = '\0';
    }
    return (dest);
}

int my_str_isnum1(char *str)
{
    int i;
    int is_alpha;

    is_alpha = 1;
    i = -1;
    while (str[(i = i + 1)] != '\0') {
        if (!(str[i] < 47 && str[i] > 58) && str[i] != 32)
            is_alpha = 0;
    }
    return (is_alpha);
}