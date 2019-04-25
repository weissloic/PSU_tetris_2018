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
        tetris->register_keybind[i] = malloc(sizeof(char) * my_strlen("^EOD"));
    }
    tetris->register_keybind[0] =  tetris->key_left;
    tetris->register_keybind[1] =  tetris->key_right;
    tetris->register_keybind[2] =  tetris->key_turn;
    tetris->register_keybind[3] =  tetris->key_drop;
    tetris->register_keybind[4] =  tetris->key_quit;
    tetris->register_keybind[5] =  tetris->key_pause;
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

        if (my_strcmp(tetris->register_keybind[i], tetris->key_right) == 0)
            counter_right++;
        if (my_strcmp(tetris->register_keybind[i], tetris->key_turn) == 0)
            counter_turn++;
        if (my_strcmp(tetris->register_keybind[i], tetris->key_drop) == 0)
            counter_drop++;
        if (my_strcmp(tetris->register_keybind[i], tetris->key_quit) == 0)
            counter_quit++;
        if (my_strcmp(tetris->register_keybind[i], tetris->key_pause) == 0)
            counter_pause++;
        if (my_strcmp(tetris->register_keybind[i], tetris->key_left) == 0)
            counter_left++;
    }
    

    if (counter_left != 1 || counter_right != 1 || counter_turn != 1 ||
        counter_drop != 1 || counter_pause != 1 || counter_quit != 1) {

    my_printf("%s\n", "KEYBIND ALREADY EXIST");
        return (84);
    }

}

void init_keybinding(tetris_t *tetris)
{
    tetris->key_left = "^EOD";
    tetris->key_right = "^EOC";
    tetris->key_turn = "^EOA";
    tetris->key_drop = "^EOB";
    tetris->key_quit = "q";
    tetris->key_pause = " ";
    tetris->level_num = 1;
    tetris->map_size_col = 20;
    tetris->map_size_row = 10;
    tetris->next_tetris = "Yes";
}