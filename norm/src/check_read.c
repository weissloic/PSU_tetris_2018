/*
** EPITECH PROJECT, 2019
** read map to check if every char is right
** File description:
** check_read
*/
#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str == NULL)
        return (NULL);
    str = my_strcpy(str, src);
    return (str);
}

char **my_str_to_word_array(char const *buffer)
{
    char **word_array;
    int n = 0;
    int x = 0;
    int y = 0;

    word_array = malloc(sizeof(char *) * (size_line(buffer) + 2));
    while (buffer[y] != '\0') {
        for (x = 0; condition(buffer[x + y]); x++);
        if (x != 0) {
            word_array[n] = malloc(sizeof(char) * x + 2);
            my_strncpy(word_array[n], buffer + y, x);
            word_array[n][x] = '\0';
            n++;
            y += x;
        }
        if (buffer[y] != '\0')
            y++;
    }
    word_array[n] = NULL;
    return (word_array);
}

int my_str_isnum2(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' && str[i] > '9') || str[i] != ' ' || str[i] != '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}

char *my_strcat1(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (int j = 0; j < my_strlen(dest); j++)
        tmp[j] = dest[j];
    for (i = 0; i < my_strlen(src); i++)
        tmp[length + i] = src[i];
    tmp[length + i] = '\0';
    return (tmp);
}