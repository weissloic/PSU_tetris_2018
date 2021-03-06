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

int display_help(char *str)
{
    int fd;
    int size;
    char buff[800];

    my_printf("Usage: %s [options]\n", str);
    fd = open("help", O_RDONLY);
    if (fd < 0)
        exit(84);
    size = read(fd, buff, sizeof(buff));
    if (size <= 0)
        exit(84);
    my_printf("%s", buff);
    close(fd);
    return (0);
}

void freearray(char **a, int m)
{
    int i;
    for (i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}

void display_error(void)
{
    write(2, "ERROR\n", 7);
    write(1, "ERROR\n", 7);
    exit(84);
}