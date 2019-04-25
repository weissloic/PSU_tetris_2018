/*
** EPITECH PROJECT, 2019
** display
** File description:
** display
*/
#include "../include/my.h"

int condition(char c)
{
    if (c != '\t' && c != '\0' && c != '\n')
        return (1);
    return (0);
}

int display_help(char *name)
{
    char *s;
    int fd = open("help", O_RDONLY);
    printf("Usage: %s [options]\n", name);
    while (s = get_next_line(fd)) {
        printf("%s\n", s);
        free(s);
    }
}

void freeArray(char **a, int m)
{
    int i;
    for (i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}