/*
** EPITECH PROJECT, 2019
** count
** File description:
** count
*/
#include "../include/my.h"

int count_line_return(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            counter++;
    }
    return (counter);
}

int count_space_str(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            counter++;
    }
    return (counter);
}

int size_line(char const *str)
{
    int n = 0;
    int nb_line = 0;

    while (str[n] != '\0') {
        if (str[n] == '\n')
            nb_line++;
        n++;
    }
    return (nb_line);
}

int display_debug_bind(tetris_t *tetris)
{
    register_binding(tetris);
    if (check_binding(tetris) == 84)
        display_error();
    if (tetris->init_debug == 1) {
        init_debug_mode(tetris);
        tetris->init_debug = 0;
    }
}