/*
** EPITECH PROJECT, 2019
** Delivery
** File description:
** get_infos
*/
#include "../include/my.h"

void get_name(tetris_t *tetris)
{
    int j = 0;
    int i = 0;

    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        for (j = 0; j != my_strlen(tetris->register_tetrimino_file[k]) - 10;
        j++) {
            tetris->name_tetrimino[k][j] =
            tetris->register_tetrimino_file[k][j];
        }
        tetris->name_tetrimino[k][j] = '\0';
    }
}

void get_number_first_line(tetris_t *tetris, int i)
{
    tetris->tetrimino[i].width =
    my_atoi(get_width(tetris->tetrimino[i].tetrimino[0]));
    tetris->tetrimino[i].height =
    my_atoi(get_height(tetris->tetrimino[i].tetrimino[0]));
    tetris->tetrimino[i].color =
    my_atoi(get_color(tetris->tetrimino[i].tetrimino[0]));
}

char *get_width(char *width)
{
    int i = 0;
    char *register_width = malloc(sizeof(char) * (my_strlen(width) + 1));

    for (; width[i] != ' '; i++) {
        register_width[i] = width[i];
    }
    register_width[i] = '\0';
    return (register_width);
}

char *get_height(char *height)
{
    int k = 0;
    int j = 0;
    int i = 1;
    int o = 0;
    int space = 0;
    char *register_height = malloc(sizeof(char) * (my_strlen(height) + 1));
    int counter = 0;
    for (; height[o] != ' '; o++) {
    }
    for (; height[o] == ' '; o++);
    for (; height[o] != ' '; o++) {

        register_height[k] = height[o];
        k++;
    }
    register_height[k] = '\0';

    return (register_height);
}

char *get_color(char *color)
{
    int k = 0;
    int o = 0;
    char *register_color = malloc(sizeof(char) * (my_strlen(color) + 1));

    for (; color[o] != ' '; o++);
    for (; color[o] == ' '; o++);
    for (; color[o] != ' '; o++);
    for (; color[o] == ' '; o++);
    for (; color[o] != '\0'; o++) {

        register_color[k] = color[o];
        k++;
    }
    register_color[k] = '\0';
    return (register_color);
}