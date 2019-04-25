/*
** EPITECH PROJECT, 2019
** error managment
** File description:
** errors
*/
#include "../include/my.h"

int check_size(solver_t *solver)
{
    char *str = malloc(sizeof(char) * my_strlen(solver->map[0]) + 1);
    char *str2 = malloc(sizeof(char) * my_strlen(solver->map[0]) + 1);
    int count = 0;
    int count2 = 0;
    int a = 0;
    solver->lenght = 0;
    solver->width = 0;

    for (int i = 0; i != my_strlen(solver->map[0]); i++) {
        if (solver->map[0][i] == ' ' && count == 0) {
            count++;
            solver->lenght = my_getnbr(str);
            int a = 0;
            count2++;
        } else if (solver->map[0][i] == ' ' && count == 1) {
            solver->width = my_getnbr(str2);
        } else if (count2 == 0){
            str[a] = solver->map[0][i];
            a++;
        } else if (count2 == 1) {
            str2[a] = solver->map[0][i];
            a++;
        }
    }
    solver->cols = check_cols(solver);
    solver->lines = check_lines(solver);
    if (solver->lines != solver->width || solver->cols != solver->lenght) {
        return (84);
    }

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