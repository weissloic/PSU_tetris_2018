/*
** EPITECH PROJECT, 2019
** replace keys 2
** File description:
** replace_keys2
*/
#include "../include/my.h"

int replace_keypause(char *optarg, tetris_t *tetris)
{
    if (optarg == NULL)
        tetris->key_pause = my_strdup('\0');

        if (my_strlen(optarg) != 1)
        exit (84);


    tetris->key_pause = my_strdup(optarg);
}