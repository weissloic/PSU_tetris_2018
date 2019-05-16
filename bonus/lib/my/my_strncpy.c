/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpy
*/

#include <stddef.h>
#include <stdlib.h>


char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        if (n > 0) {
            dest[i] = src[i];
            n--;
        }
    }
    return (dest);
}
