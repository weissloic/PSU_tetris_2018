/*
** EPITECH PROJECT, 2019
** get_infos2
** File description:
** get_infos2
*/
#include "../include/my.h"

void get_form_tetrimino(tetris_t *tetris)
{
    int j;
    int i = 0;
    int o = 0;

    for (; i != tetris->get_number_tetrimino; i++) {
        j = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (int k = 1; tetris->tetrimino[i].tetrimino[k] != NULL; k++) {
                tetris->tetrimino[i].form_tetrimino[j] = 
                tetris->tetrimino[i].tetrimino[k];
                j++;
            }
        }

    }
}

int get_size_file(tetris_t *tetris)
{
    struct stat fichier;
    int counter_size = 0;
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        stat(tetris->strcat_register_tetrimino_file[i], &fichier);
        if (fichier.st_size <= 2)
            tetris->tetrimino[i].error_detected = 1;
        counter_size += fichier.st_size;
    }
    return (counter_size);
}

int get_number_file(tetris_t *tetris)
{
    DIR *rep = opendir("tetriminos/");
    tetris->get_number_tetrimino = 0;
    tetris->get_max_size = 0;
    int i = 0;
    int pos = 0;

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            pos = my_strlen(ent->d_name) - 10;
            if (ent->d_name[my_strlen(ent->d_name) - 1] != '~' && 
            !(my_strcmp(&ent->d_name[pos], ".tetrimino"))) {
                tetris->get_number_tetrimino++;
            if (my_strlen(ent->d_name) > tetris->get_max_size)
                tetris->get_max_size = my_strlen(ent->d_name);
            }
        }
    }
    return 0;
}