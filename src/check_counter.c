/*
** EPITECH PROJECT, 2019
** check_counter
** File description:
** check_counter
*/
#include "../include/my.h"

int check_right(tetris_t *tetris, int i, int counter_right)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_right++;
    return (counter_right);
}

int check_left(tetris_t *tetris, int i, int counter_left)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_left++;
    return (counter_left);
}

int check_pause(tetris_t *tetris, int i, int counter_pause)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_pause++;
    return (counter_pause);
}

int check_drop(tetris_t *tetris, int i, int counter_drop)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_drop++;
    return (counter_drop);
}

int check_quit(tetris_t *tetris, int i, int counter_quit)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_quit++;
    return (counter_quit);
}