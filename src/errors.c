/*
** EPITECH PROJECT, 2019
** error managment
** File description:
** errors
*/
#include "../include/my.h"

int check_size(solver_t *solver)
{
    solver->str = malloc(sizeof(char) * my_strlen(solver->map[0]) + 1);
    solver->str2 = malloc(sizeof(char) * my_strlen(solver->map[0]) + 1);
    solver->count = 0;
    solver->count2 = 0;
    solver->a = 0;
    solver->lenght = 0;
    solver->width = 0;
    for (int i = 0; i != my_strlen(solver->map[0]); i++) {
        analyze_size(solver, i);
    }
    check_error(solver);
}

int check_cols(solver_t *solver)
{
    int cols = 0;

    for (int i = 0; i != my_strlen(solver->map[1]); i++) {
        if (solver->map[1][i] == '*') {
            cols++;
        }
    }
    return (cols);
}

int check_lines(solver_t *solver)
{
    int cols = 0;
    int i = 1;

    for (i; solver->map[i] != NULL; i++) {
        for (int j = 0; solver->map[i][j] != '\0'; j++) {
        }
    }
    i--;
    return (i);
}

void put_error_value_to_null(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        tetris->tetrimino[i].error_detected = 0;
        tetris->tetrimino[i].width = 0;
        tetris->tetrimino[i].height = 0;
        tetris->tetrimino[i].color = 0;
    }
}

int check_error(solver_t *solver)
{
    solver->cols = check_cols(solver);
    solver->lines = check_lines(solver);
    if (solver->lines != solver->width || solver->cols != solver->lenght) {
        return (84);
    }
}