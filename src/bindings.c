/*
** EPITECH PROJECT, 2019
** modify binds
** File description:
** bindings
*/
#include "../include/my.h"

void register_binding(tetris_t *tetris)
{
    tetris->register_keybind = malloc(sizeof(char *) * 6);

    for (int i = 0; i != 6; i++) {
        tetris->register_keybind[i] = malloc(sizeof(char) *
        my_strlen("^EOD") + 1);
    }
    tetris->register_keybind[0] = tetris->key_left;
    tetris->register_keybind[1] = tetris->key_right;
    tetris->register_keybind[2] = tetris->key_turn;
    tetris->register_keybind[3] = tetris->key_drop;
    tetris->register_keybind[4] = tetris->key_quit;
    tetris->register_keybind[5] = tetris->key_pause;
}

int check_binding(tetris_t *tetris)
{
    int counter_left = 0;
    int counter_right = 0;
    int counter_turn = 0;
    int counter_drop = 0;
    int counter_quit = 0;
    int counter_pause = 0;
    for (int i = 0; i != 6; i++) {
        counter_right = check_right(tetris, i, counter_right);
        counter_turn = check_turn(tetris, i, counter_turn);
        counter_drop = check_drop(tetris, i, counter_drop);
        counter_quit = check_quit(tetris, i, counter_quit);
        counter_pause = check_pause(tetris, i, counter_pause);
        counter_left = check_left(tetris, i, counter_left);
    }
    if (counter_left != 1 || counter_right != 1 || counter_turn != 1 ||
    counter_drop != 1 || counter_pause != 1 || counter_quit != 1) {
        my_printf("%s\n", "KEYBIND ALREADY EXIST");
        return (84);
    }
}

void init_keybinding(tetris_t *tetris)
{
    tetris->key_left = my_strdup("^EOD");
    tetris->key_right = my_strdup("^EOC");
    tetris->key_turn = my_strdup("^EOA");
    tetris->key_drop = my_strdup("^EOB");
    tetris->key_quit = my_strdup("q");
    tetris->key_pause = my_strdup(" ");
    tetris->level_num = 1;
    tetris->map_size_col = 10;
    tetris->map_size_row = 20;
    tetris->next_tetris = 1;
}

int fill(tetris_t *tetris, int l, int k, int i)
{
    for (; l < tetris->tetrimino[i].width; l++) {
        tetris->tetrimino[i].tetri_without_final_space[k][l] =
        tetris->tetrimino[i].form_tetrimino[k][l];
    }
    tetris->tetrimino[i].tetri_without_final_space[k][l] = '\0';
    l = 0;
    return (l);
}