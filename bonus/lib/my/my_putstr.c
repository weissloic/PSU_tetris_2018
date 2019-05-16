/*
** EPITECH PROJECT, 2018
** my_put_str.c
** File description:
** my_put_str
*/
#include "../../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}