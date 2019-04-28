/*
** EPITECH PROJECT, 2019
** check row and lines
** File description:
** check_size
*/
#include "../include/my.h"

char *check_row(tetris_t *tetris, int fill_contain_row_col, char *contain_row)
{
    for (fill_contain_row_col; optarg[fill_contain_row_col] != ','; 
    fill_contain_row_col++)
        contain_row[fill_contain_row_col] = optarg[fill_contain_row_col];
    return (contain_row);
}

char *check_line(tetris_t *tetris, int fill_contain_row_col, char *contain_col)
{
    for (fill_contain_row_col; optarg[fill_contain_row_col + 1] != '\0'; 
    fill_contain_row_col++) {
        contain_col[tetris->fill_contain] = optarg[fill_contain_row_col + 1];
        tetris->fill_contain++;
    }
    return (contain_col);
}

void transform_row_col(tetris_t *tetris, char *contain_row, char *contain_col)
{
    tetris->map_size_row = my_atoi(contain_row);
    tetris->map_size_col = my_atoi(contain_col);
}