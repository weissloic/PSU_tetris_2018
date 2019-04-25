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
        return 84;

    tetris->key_left = optarg;
}

int replace_keyright(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return 84;

    tetris->key_right = optarg;
}

int replace_keyturn(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return 84;

    tetris->key_turn = optarg;
}

int replace_keydrop(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return 84;

    tetris->key_drop = optarg;
}

int replace_keyquit(char *optarg, tetris_t *tetris)
{
    if (my_strlen(optarg) != 1)
        return 84;

    tetris->key_quit = optarg;
}