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
        for (j = 0; j != my_strlen(tetris->register_tetrimino_file[k]) - 10; j++) {
                tetris->name_tetrimino[k][j] = tetris->register_tetrimino_file[k][j];
        }
    }
}

void get_number_first_line(tetris_t *tetris, int i)
{
    char *width = malloc(sizeof(char) * 4);
    char *height = malloc(sizeof(char) * 4);
    char *color = malloc(sizeof(char) * 4);

    width = get_width(tetris->tetrimino[i].tetrimino[0]);
    height = get_height(tetris->tetrimino[i].tetrimino[0]);
    color = get_color(tetris->tetrimino[i].tetrimino[0]);
    tetris->tetrimino[i].width = my_atoi(width);
    tetris->tetrimino[i].height = my_atoi(height);
    //printf("%d\n", tetris->tetrimino[i].height);
    tetris->tetrimino[i].color = my_atoi(color);
}

char *get_width(char *width)
{
    int i = 0;
    char *register_width = malloc(sizeof(char) * 4);

    for (; width[i] != ' '; i++) {
        register_width[i] = width[i];
    }
    register_width[i + 1] = NULL;
    return (register_width);
}

char *get_height(char *height)
{
    int k = 0;
    int j = 0;
    int i = 1;
    int o = 0;
    int space = 0;
    char *register_height = malloc(sizeof(char) * 4);

    int counter = 0;

    for (; height[o] != ' '; o++) {
        //counter++;
        //printf("%c\n", height[o]);
    }

    for (; height[o] == ' '; o++);
    
        //printf("%c\n", height[o]);

    for (; height[o] != ' '; o++) {

        register_height[k] = height[o];
        k++;
    }
    //register_height[o + 1] = NULL;

    //printf("%s\n", register_height);

    return (register_height);
}

char *get_color(char *color)
{
    int k = 0;
    int o = 0;
    char *register_color = malloc(sizeof(char) * 4);


    int counter = 0;

    for (; color[o] != ' '; o++);

    for (; color[o] == ' '; o++);
    
        //printf("%c\n", height[o]);

    for (; color[o] != ' '; o++);

    for (; color[o] == ' '; o++);

        for (; color[o] != '\0'; o++) {

        register_color[k] = color[o];
        k++;
    }
    register_color[o] = NULL;

    return (register_color);
}