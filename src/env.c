/*
** EPITECH PROJECT, 2019
** check env
** File description:
** env
*/
#include "../include/my.h"

int check_env(char **env)
{
    if (env == NULL || env[0] == NULL)
        return (84);
}

char *get_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++)
        if (!my_strncmp("TERM=", env[i], 4))
            return ((char *)(env[i] + 5));
    return (NULL);
}