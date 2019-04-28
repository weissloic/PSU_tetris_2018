/*
** EPITECH PROJECT, 2019
** check args 3
** File description:
** check_args3
*/
#include "../include/my.h"

void check_args_eleven(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "map-size") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "debug") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "without-next") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_twelve(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "key-drop") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "key-quit") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "key-pause") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_thirteen(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "key-turn") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "key-left") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}