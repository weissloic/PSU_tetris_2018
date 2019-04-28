/*
** EPITECH PROJECT, 2019
** check error tetrimino
** File description:
** error_tetrimino
*/
#include "../include/my.h"

int error_max_lenght(tetris_t *tetris, int i, int check_len, int max_lenght)
{
    if (max_lenght == tetris->tetrimino[i].width)
        check_len++;
    return (check_len);
}

int error_count_space(tetris_t *tetris, int i, int counter_space, int j)
{
    if (tetris->tetrimino[i].form_tetrimino[j][0] == ' ')
        counter_space++;
    return (counter_space);
}

int error_star_line(tetris_t *tetris, int i, int j)
{
    if ((tetris->tetrimino[i].form_tetrimino[j][0] == ' ' &&
    (check_stars_line(tetris->tetrimino[i].form_tetrimino[j]) > 0))
    || tetris->tetrimino[i].form_tetrimino[j][0] == '*') {
        tetris->counter++;
    }
    return (tetris->counter);
}

int error_false_letter(tetris_t *tetris, int i, int j, int falsel)
{
    if (check_letter_str(tetris->tetrimino[i].form_tetrimino[j]) != 0)
        falsel++;
    return (falsel);
}

void check_errors(tetris_t *tetris, int i, int falsel, int counter_space)
{
    if (tetris->counter != tetris->tetrimino[i].height ||
    counter_space == tetris->tetrimino[i].height ||
    falsel != 0 ||
    tetris->tetrimino[i].color > 7)
        tetris->tetrimino[i].error_detected = 1;
}