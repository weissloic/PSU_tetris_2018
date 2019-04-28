/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** my_strcpy
*/
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}