/*
** EPITECH PROJECT, 2019
** printing debug mode
** File description:
** print
*/
#include "../include/my.h"

void print_keys(tetris_t *tetris)
{
    char *space = "(space)";
    int left = (my_strcmp(tetris->key_left, " ") == 0) ?
    my_printf("Key Left : %s\n", space) : 
    my_printf("Key Left : %s\n", tetris->key_left);
    int right = (my_strcmp(tetris->key_right, " ") == 0) ? 
    my_printf("Key Left : %s\n", space) : 
    my_printf("Key Right : %s\n", tetris->key_right);
    int turn = (my_strcmp(tetris->key_turn, " ") == 0) ? 
    my_printf("Key Turn : %s\n", space) : 
    my_printf("Key Turn : %s\n", tetris->key_turn);
    int drop = (my_strcmp(tetris->key_drop, " ") == 0) ? 
    my_printf("Key Drop : %s\n", space) : 
    my_printf("Key Drop : %s\n", tetris->key_drop);
    int quit = (my_strcmp(tetris->key_quit, " ") == 0) ? 
    my_printf("Key Quit : %s\n", space) : 
    my_printf("Key Quit : %s\n", tetris->key_quit);
    int pause = (my_strcmp(tetris->key_pause, " ") == 0) ? 
    my_printf("Key Pause : %s\n", space) : 
    my_printf("Key Pause : %s\n", tetris->key_pause);
}

void print_infos(tetris_t *tetris)
{
    char *yes = "Yes";
    char *no = "No";
    int next = tetris->next_tetris == 0 ? 
    my_printf("Next : %s\n", no) : 
    my_printf("Next : %s\n", yes);
    my_printf("Level : %d\n", tetris->level_num);
    my_printf("Size : %d*%d\n", tetris->map_size_row, tetris->map_size_col);
    my_printf("Tetriminos : %d\n", tetris->get_number_tetrimino);
}

void print_tetriminos(tetris_t *tetris, int i)
{
    if (tetris->tetrimino[i].error_detected == 0) {
        my_printf(" Size %d*%d :", 
        tetris->tetrimino[i].width, tetris->tetrimino[i].height);
        my_printf(" Color %d :", tetris->tetrimino[i].color);
        my_printf("\n");
        for (int j = 0; j != tetris->tetrimino[i].height; j++) {
            my_printf("%s\n", 
            tetris->tetrimino[i].tetri_without_final_space[j]);
        }
    } else if (tetris->tetrimino[i].error_detected == 1) {
        my_printf("%s\n", " Error");
    }
}