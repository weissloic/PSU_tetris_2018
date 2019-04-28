/*
** EPITECH PROJECT, 2019
** check_infos2
** File description:
** check_infos2
*/
#include "../include/my.h"

int row_check(tetris_t *tetris, char *optarg)
{
    for (tetris->fill_contain_row_col;
    optarg[tetris->fill_contain_row_col] != ','; 
    tetris->fill_contain_row_col++)
        (tetris->contain_row[tetris->fill_contain_row_col] =
        optarg[tetris->fill_contain_row_col]);
    for (tetris->fill_contain_row_col;
    optarg[tetris->fill_contain_row_col + 1] != '\0'; 
    tetris->fill_contain_row_col++) {
        (tetris->contain_col[tetris->fill_contain_n] =
        optarg[tetris->fill_contain_row_col + 1]);
        tetris->fill_contain_n++;
    }
}

int check_map_size(tetris_t *tetris, char *optarg)
{
    int counter_star_char_map = 0;
    tetris->contain_row = malloc(sizeof(char) * 4);
    tetris->contain_col = malloc(sizeof(char) * 4);
    tetris->fill_contain_row_col = 0;
    tetris->fill_contain_n = 0;
    tetris->valid_string = 0;
    for (int i = 0; optarg[i] != '\0'; i++) {
        if ((optarg[i] < '0' || optarg[i] > '9') && optarg[i] != ',')
            tetris->valid_string = 1;
        if (optarg[i] == ',')
            counter_star_char_map += 1;
    }
    if (counter_star_char_map == 1 && tetris->valid_string == 0) {
        row_check(tetris, optarg);
    }
    tetris->map_size_row = my_atoi(tetris->contain_row);
    tetris->map_size_col = my_atoi(tetris->contain_col);
    if (tetris->map_size_row <= 0 || tetris->map_size_col <= 0)
        return 84;
}