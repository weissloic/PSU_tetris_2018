/*
** EPITECH PROJECT, 2019
** open
** File description:
** open
*/
#include "../include/my.h"

int open_txt(tetris_t *tetris)
{
    char **register_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (int i = 0; i != tetris->get_number_tetrimino; i++)
        register_file[i] = malloc(sizeof(char) * get_size_file(tetris) + 1);

    int fd;
    int size;

    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        if (tetris->tetrimino[k].error_detected == 0) {
            fd = open(tetris->strcat_register_tetrimino_file[k], O_RDONLY);
            if (fd < 0)
                tetris->tetrimino[k].error_detected == 1;
            size = read(fd, register_file[k], (get_size_file(tetris)));
            if (size <= 0)
                tetris->tetrimino[k].error_detected == 1;
        }
    }
    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        tetris->tetrimino[k].tetrimino = NULL;
        if (tetris->tetrimino[k].error_detected == 0)
            tetris->tetrimino[k].tetrimino = my_str_to_word_array(register_file[k], tetris);
    }
    return (0);
}

int reopen_get_number_file(tetris_t *tetris)
{
    DIR *rep = opendir("tetriminos/");
    int i = 0;
    int j = 0;
    int pos = 0;

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            pos = my_strlen(ent->d_name) - 10;
            if (ent->d_name[my_strlen(ent->d_name) - 1] != '~' && !(my_strcmp(&ent->d_name[pos], ".tetrimino"))) {
                tetris->register_tetrimino_file[i] = ent->d_name;
                i++;
            }
        }
    }
    return 0;
}