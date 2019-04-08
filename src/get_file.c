/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"


int display_help(void)
{
    int fd;
    int size;
    char buff[800];

    fd = open("help", O_RDONLY);
    if (fd < 0)
        return (84);
    size = read(fd, buff, sizeof(buff));
    if (size <= 0)
        return (84);
    my_printf("%s\n", buff);
    close(fd);
    return (0);
}

int main (int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    //char temp[25];
    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (display_help());

    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    for (int i = 0; tetris->register_tetrimino_file[i] != NULL; i++) {
        printf("%s\n", tetris->register_tetrimino_file[i]);
    }


}

void sort(char **s,int n, tetris_t *tetris)
{
    int i = 0;
    int j = 0;
    int cmp = 0;
    char tmp[1][tetris->get_number_tetrimino];

    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++) {
            cmp = strcmp(s[j],s[j+1]);
            if (cmp > 0) {
                strcpy(tmp[0],s[j+1]);
                strcpy(s[j+1],s[j]);
                strcpy(s[j],tmp[0]);
            }   
        }
}

int get_number_file(tetris_t *tetris)
{
    DIR * rep = opendir ("test_tetris/");
    tetris->get_number_tetrimino = 0;
    tetris->get_max_size = 0;
    int i = 0;

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~') {
                tetris->get_number_tetrimino++;
            if (my_strlen(ent->d_name) > tetris->get_max_size)
                tetris->get_max_size = my_strlen(ent->d_name);
            }
        }
    closedir (rep);
    }
    return 0;
}

int reopen_get_number_file(tetris_t *tetris)
{
    DIR * rep = opendir ("test_tetris/");
    tetris->get_max_size = 0;
    int i = 0;

    if (rep != NULL) {
        struct dirent *ent;

        while ((ent = readdir(rep)) != NULL){
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~') {
                tetris->register_tetrimino_file[i] = ent->d_name;
                i++;
            }
            tetris->register_tetrimino_file[i] = NULL;
        }
    closedir (rep);
    }
    return 0;
}

int malloc_file_array(tetris_t *tetris)
{
    tetris->register_tetrimino_file = NULL;
    int i = 0;

    tetris->register_tetrimino_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (i; i != tetris->get_max_size; i++)
        tetris->register_tetrimino_file[i] = malloc(sizeof(char) * tetris->get_max_size);
}