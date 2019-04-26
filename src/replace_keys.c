/*
** EPITECH PROJECT, 2019
** replace keys 1
** File description:
** replace_keys
*/
#include "../include/my.h"

int replace_keyleft(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return;

    tetris->key_left = my_strdup(optarg);
}

int replace_keyright(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return;

    tetris->key_right = my_strdup(optarg);
}

int replace_keyturn(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return;

    tetris->key_turn = my_strdup(optarg);
}

int replace_keydrop(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return;

    tetris->key_drop = my_strdup(optarg);
}

int replace_keyquit(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return;

    tetris->key_quit = my_strdup(optarg);
}