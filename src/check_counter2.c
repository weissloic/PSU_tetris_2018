/*
** EPITECH PROJECT, 2019
** check_counter2
** File description:
** check_counter2
*/
#include "../include/my.h"

int check_turn(tetris_t *tetris, int i, int counter_turn)
{
    if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
        counter_turn++;
    return (counter_turn);
}