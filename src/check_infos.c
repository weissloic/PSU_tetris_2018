/*
** EPITECH PROJECT, 2019
** check infos
** File description:
** check_infos
*/
#include "../include/my.h"

int check_letter_str(char *str)
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '*' && str[i] != '\n' && str[i] != '\0')
            counter++;
    }
    return (counter);
}

int check_stars_line(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '*')
            counter++;

    return (counter);
}

int check_first_line(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        if (tetris->tetrimino[i].error_detected == 0) {
            if (tetris->tetrimino[i].tetrimino[0][0] == '\0')
                tetris->tetrimino[i].error_detected = 1;
            else if (count_space_str(tetris->tetrimino[i].tetrimino[0]) >= 2 
            && (tetris->tetrimino[i].tetrimino[0][0] >= '0' &&
            tetris->tetrimino[i].tetrimino[0][0] <= '9')
            && my_str_isnum2(tetris->tetrimino[i].tetrimino[0]) == 1 && 
            tetris->tetrimino[i].error_detected == 0) {
                get_number_first_line(tetris, i);
            } else
                tetris->tetrimino[i].error_detected = 1;
        }
    }
}

void check_error_tetrimino(tetris_t *tetris)
{
    tetris->counter = 0;
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        tetris->counter = 0;
        int counter_space = 0;
        int falsel = 0;
        int check_len = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (int j = 0; j != tetris->tetrimino[i].height; j++) {
                int max_lenght = 0;
                falsel = error_false_letter(tetris, i, j, falsel);
                tetris->counter = error_star_line(tetris, i, j);
                counter_space = error_count_space(tetris, i, counter_space, j);
                max_lenght = my_strlen(tetris->tetrimino[i].form_tetrimino[j]);
                check_len = error_max_lenght(tetris, i, check_len, max_lenght);
            }
            len_check(tetris, i, check_len);
            check_errors(tetris, i, falsel, counter_space);
        }
    }
}


int check_level(tetris_t *tetris, char *optarg)
{
    int bool_letter_level = 0;

    for (int i = 0; optarg[i] != '\0'; i++) {
        if (optarg[i] >= '0' && optarg[i] <= '9')
            bool_letter_level = 1;
    }
    if (bool_letter_level == 1)
        tetris->level_num = my_getnbr(optarg);
    else {
        my_printf("WRONG LEVEL\n");
        return (84);
    }
}