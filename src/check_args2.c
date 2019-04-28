/*
** EPITECH PROJECT, 2019
** check args 3
** File description:
** check_args2
*/
#include "../include/my.h"

void check_args_six(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--level=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-right=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-turn=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_seven(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--key-drop=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-quit=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_eight(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strncmp(argv[i], "-L=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strncmp(argv[i], "-l=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strncmp(argv[i], "-r=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_nine(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strncmp(argv[i], "-q=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strncmp(argv[i], "-p=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_ten(int argc, char **argv)
{
    check_args_eleven(argc, argv);
    check_args_twelve(argc, argv);
    check_args_thirteen(argc, argv);
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "level") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "key-right") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }   
}