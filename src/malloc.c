/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc
*/
#include "../include/my.h"

void malloc_tetrimino_struct(tetris_t *tetris)
{
    int k = 0;
    int i = 0;
    for (; i != tetris->get_number_tetrimino; i++) {
        if (tetris->tetrimino[i].error_detected == 0) {
            tetris->tetrimino[i].form_tetrimino =
            (char **)malloc(sizeof(char *) *
            (tetris->tetrimino[i].height + 1));
            k = 0;
            for (; k <= tetris->tetrimino[i].height; k++) {
                tetris->tetrimino[i].form_tetrimino[k] =
                (char *)malloc(sizeof(char) *
                (tetris->tetrimino[i].width + 2));
            }
        }

    }
}

void malloc_tetrimino_without_space(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        if (tetris->tetrimino[i].error_detected == 0) {
            tetris->tetrimino[i].tetri_without_final_space =
            malloc(sizeof(char *) * tetris->tetrimino[i].height + 1);
            for (int k = 0; k != tetris->tetrimino[i].height; k++) {
                tetris->tetrimino[i].tetri_without_final_space[k] =
                malloc(sizeof(char) * tetris->tetrimino[i].width + 1);
            }
        }
    }
}

int malloc_file_array(tetris_t *tetris)
{
    int i = 0;
    int j = 0;
    int k = 0;
    tetris->register_tetrimino_file =
    malloc(sizeof(char *) * (tetris->get_number_tetrimino + 1));
    tetris->name_tetrimino =
    malloc(sizeof(char *) * (tetris->get_number_tetrimino + 100));
    tetris->strcat_register_tetrimino_file =
    malloc(sizeof(char *) * (tetris->get_number_tetrimino + 1));
    for (i; i != tetris->get_number_tetrimino; i++)
        tetris->register_tetrimino_file[i] = malloc(sizeof(char) *
        (tetris->get_max_size + 1));
    for (j; j != tetris->get_number_tetrimino + 1; j++)
        tetris->name_tetrimino[j] = malloc(sizeof(char) *
        (tetris->get_max_size - my_strlen(".tetrimino") + 1));

    for (k; k != tetris->get_number_tetrimino; k++)
        tetris->strcat_register_tetrimino_file[k] = malloc(sizeof(char) *
        (tetris->get_max_size + my_strlen("tetrimino/") + 1));
}