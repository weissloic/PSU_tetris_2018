/*
** EPITECH PROJECT, 2019
** set read
** File description:
** set_read
*/
#include "../include/my.h"

void set_read_mode(int mode)
{
    static struct termios termsave;
    static struct termios term;
    if (mode == 1) {
        ioctl(0, TCGETS, &term);
        ioctl(0, TCGETS, &termsave);
        term.c_lflag &= ~ECHO;
        term.c_lflag &= ~ICANON;
        term.c_cc[VMIN] = 1;
        term.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, &term);
    } else if (mode == 2) {
        set_mode_one(&termsave, &term);
    } else
    ioctl(0, TCSETS, &termsave);
}

void set_mode_one(struct termios *termsave, struct termios *term)
{
    ioctl(0, TCGETS, &term);
    ioctl(0, TCGETS, &termsave);
    term->c_lflag &= ~ECHO;
    term->c_lflag &= ~ICANON;
    term->c_cc[VMIN] = 0;
    term->c_cc[VTIME] = 0;
    ioctl(0, TCSETS, &term);
}