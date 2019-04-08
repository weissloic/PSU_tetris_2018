/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/
#include "../include/my.h"
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int manage_window(void)
{
    int ch;
    int x = 0;
    int y = 0;
    int c = 0;
    int d = 1;
    int e = 1;
    int f = 1;
    int a = 20;
    int b = 20;
    int *cox = malloc(sizeof(int) * 3 + 1);
    int *coy = malloc(sizeof(int) * 3 + 1);

    cox[0] = x;
    cox[1] = c;
    cox[2] = e;
    coy[0] = y;
    coy[1] = d;
    coy[2] = f;

    initscr();
    while(1) {
        curs_set(0);
        noecho();
        keypad(stdscr, TRUE);
        mvprintw(cox[0], coy[0], "A");
        mvprintw(cox[1], coy[1], "B");
        mvprintw(cox[2], coy[2], "C");
        mvprintw(a, b, "X");
        refresh();
        ch = getch();
        if(ch == ' ') {
            endwin();
            break;
        } if (ch == KEY_UP) {
            for (int i = 0; i != 3; i++) {
                cox[i]--;
            }
        } if (ch == KEY_LEFT) {
            for (int i = 0; i != 3; i++) {
                coy[i]--;
            }
        } if (ch == KEY_RIGHT) {
            for (int i = 0; i != 3; i++) {
                coy[i]++;
            }
        } if (ch == KEY_DOWN) {
            for (int i = 0; i != 3; i++) {
                cox[i]++;
            }
        }
        clear();
    }
    return (0);
}

int main (int ac, char **av)
{
    solver_t *solver = malloc(sizeof(solver_t));
    solver->map = get_map(solver, av[1]);

    int i = 0;

    while (solver->map[i] != NULL) {
        printf("%s", solver->map[i]);
        i++;
    }
    if (check_size(solver) == 84) {
        return (84);
    }
    manage_window();
    return (0);
}