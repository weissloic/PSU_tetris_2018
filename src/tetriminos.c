/*
** EPITECH PROJECT, 2019
** create tetriminos
** File description:
** tetriminos
*/
#include "../include/my.h"

int create_teriminos(tetris_t *tetris)
{
    init_tetriminos(tetris);
    for (int k = 0;k != tetris->get_number_tetrimino; k++) {
        tetris->strcat_register_tetrimino_file[k] =
        my_strcat1("tetriminos/", tetris->register_tetrimino_file[k]);
    }
    tetris->tetrimino = malloc(sizeof(tetrimino_t) *
    tetris->get_number_tetrimino);
    put_error_value_to_null(tetris);
    if (open_txt(tetris) == 84)
        return (84);
    check_first_line(tetris);
    malloc_tetrimino_struct(tetris);
    get_form_tetrimino(tetris);
    malloc_tetrimino_without_space(tetris);
    check_error_tetrimino(tetris);
    fill_tetris_without_space(tetris);
    return (0);
}

void init_tetriminos(tetris_t *tetris)
{
    init_keybinding(tetris);
    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);
}

void len_check(tetris_t *tetris, int i, int check_len)
{
    if (check_len == 0)
        tetris->tetrimino[i].error_detected = 1;
}