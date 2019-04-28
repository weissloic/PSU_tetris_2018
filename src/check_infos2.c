/*
** EPITECH PROJECT, 2019
** check_infos2
** File description:
** check_infos2
*/
#include "../include/my.h"

int check_map_size(tetris_t *tetris, char *optarg)
{
    int counter_star_char_map = 0;
    char *contain_row = malloc(sizeof(char) * 4);
    char *contain_col = malloc(sizeof(char) * 4);
    int fill_contain_row_col = 0;
    int fill_contain = 0;
    int valid_string = 0;
    for (int i = 0; optarg[i] != '\0'; i++) {
        if ((optarg[i] < '0' || optarg[i] > '9') && optarg[i] != ',')
            valid_string = 1;
        if (optarg[i] == ',')
            counter_star_char_map += 1;
    }
    if (counter_star_char_map == 1 && valid_string == 0) {
        for (fill_contain_row_col; optarg[fill_contain_row_col] != ','; fill_contain_row_col++)
            contain_row[fill_contain_row_col] = optarg[fill_contain_row_col];

        for (fill_contain_row_col; optarg[fill_contain_row_col + 1] != '\0'; fill_contain_row_col++) {
            contain_col[fill_contain] = optarg[fill_contain_row_col + 1];
            fill_contain++;
        }
    }
    tetris->map_size_row = my_atoi(contain_row);
    tetris->map_size_col = my_atoi(contain_col);
    if (tetris->map_size_row <= 0 || tetris->map_size_col <= 0)
        return 84;
}