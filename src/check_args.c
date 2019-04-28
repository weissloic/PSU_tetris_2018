/*
** EPITECH PROJECT, 2019
** check args
** File description:
** check_args
*/
#include "../include/my.h"

void check_arg(char **argv, int argc)
{
    check_args_four(argc, argv);
    check_args_five(argc, argv);
    check_args_six(argc, argv);
    check_args_seven(argc, argv);
    check_args_eight(argc, argv);
    check_args_nine(argc, argv);
    check_args_ten(argc, argv);
    for (int i = 0; i != argc; i++) {
        if (my_strncmp(argv[i], "-t=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strncmp(argv[i], "-d=", 3) == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_arg_two(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--key-pause=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--map-size=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }   
}

void check_arg_three(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--key-turn") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-drop") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-quit") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }   
}

void check_args_four(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--level") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-right") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--key-left=") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}

void check_args_five(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        if (my_strcmp(argv[i], "--key-pause") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
        if (my_strcmp(argv[i], "--map-size") == 0) {
            write(2, "ERROR\n", 7);
            write(1, "ERROR\n", 7);
            exit(84);
        }
    }
}