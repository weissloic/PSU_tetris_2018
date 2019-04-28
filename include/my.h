/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my h
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <termios.h>

# include <time.h>
# include <ncurses.h>
# include <curses.h>

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <dirent.h>


#ifndef MY_H_
#define MY_H_
#define READ_SIZE 80

static struct option long_options[] = {
    {"level",     required_argument, 0,  'L' },
    {"key-left",  required_argument, 0, 'l'},
    {"key-right",  required_argument, 0, 'r'},
    {"key-turn",  required_argument, 0, 't'},
    {"key-drop",  required_argument, 0, 'd'},
    {"key-quit",  required_argument, 0, 'q'},
    {"key-pause",  required_argument, 0, 'p'},
    {"map-size",  required_argument, 0, 'm'},
    {"without-next",  0, NULL, 'w'},
    {"debug",  no_argument, 0, 'D'},
    {"help",  no_argument, 0, 'h'},
    {NULL, 0, NULL, 0}
};

typedef struct tetrimono_s {
    char **tetrimino;
    char **form_tetrimino;
    char **tetri_without_final_space;
    int width;
    int height;
    int color;
    int error_detected;
} tetrimino_t;

typedef struct tetris_s {
    int get_number_tetrimino;
    char **register_tetrimino_file;
    int get_max_size;
    char **name_tetrimino;
    char **strcat_register_tetrimino_file;
    int level_num;
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int next_tetris;
    char **register_keybind;
    int map_size_col;
    int map_size_row;
    int without_next;
    tetrimino_t *tetrimino;
    int counter;
    int fill_contain;
    int fill_contain_row_col;
    int fill_contain_n;
    int valid_string;
    char *contain_row;
    char *contain_col;
    char **register_file;
} tetris_t;

typedef struct solver {
    char **map;
    int lenght;
    int width;
    int cols;
    int lines;
    int a;
    int count;
    int count2;
    char *str;
    char *str2;
} solver_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *get_next_line(int fd);
static int find_retline(char *str, int first, int size);
static char *manage_str(char *str1, char *str2, int *line);
static int nb_alloc(char *str1, char *str2, int cpy);
char *str_concat(char *str1, char *str2, int start_cpy, int stop_cpy);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *s, ...);
void display_int(va_list ap);
void display_string(va_list ap);
void display_char(va_list ap);
void display_pointer(va_list ap);
int convert_tobase(int nbr, char *base);
void convert_to_bin(va_list ap);
void convert_to_octo(va_list ap);
void convert_to_hexa(va_list ap);
void convert_to_mhexa(va_list ap);
void display_unsigned(va_list ap);
long my_put_long_nbr(long nb);
unsigned int my_put_unsigned_nbr(unsigned int nb);
int my_put_unsigned_str(char const *str);
void display_unprintable(va_list ap);
void display_percentage();
char **get_map(solver_t *solver, const char *path);
int get_number_line(const char *path);
static char **malloc_map(int line);
char *get_color(char *color);
char *get_height(char *height);
char *get_width(char *width);
int check_lines(solver_t *solver);
int check_cols(solver_t *solver);
int size_line(char const *str);
int condition(char c);
int display_help(char *name);
int count_line_return(char *str);
int get_size_file(tetris_t *tetris);
void fill_tetris_without_space(tetris_t *tetris);
int check_letter_str(char *str);
void get_form_tetrimino(tetris_t *tetris);
int check_stars_line(char *str);
void check_error_tetrimino(tetris_t *tetris);
int open_txt(tetris_t *tetris);
void put_error_value_to_null(tetris_t *tetris);
int check_first_line(tetris_t *tetris);
int count_space_str(char *str);
void set_read_mode(int mode);
void freeArray(char **a, int m);
void sort(char **s,int n, tetris_t *tetris);
int get_number_file(tetris_t *tetris);
int reopen_get_number_file(tetris_t *tetris);
void init_debug_mode(tetris_t *tetris);
int check_map_size(tetris_t *tetris, char *optarg);
int check_level(tetris_t *tetris, char *optarg);
char *my_strdup(char const *src);
char **my_str_to_word_array(char *buffer, tetris_t *tetris);
int my_str_isnum2(char *str);
char *my_strcat1(char *dest, char const *src);
int replace_keyleft(char *optarg, tetris_t *tetris);
int replace_keyright(char *optarg, tetris_t *tetris);
int replace_keyturn(char *optarg, tetris_t *tetris);
int replace_keydrop(char *optarg, tetris_t *tetris);
int replace_keyquit(char *optarg, tetris_t *tetris);
int replace_keypause(char *optarg, tetris_t *tetris);
void register_binding(tetris_t *tetris);
int check_binding(tetris_t *tetris);
void init_keybinding(tetris_t *tetris);
char *my_strdup(char const *src);
int my_str_isnum2(char *str);
char *my_strcat1(char *dest, char const *src);
unsigned my_atoui(char *str);
int my_atoi(char *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_str_isnum1(char *str);
void get_name(tetris_t *tetris);
void get_number_first_line(tetris_t *tetris, int i);
char *get_width(char *width);
char *get_height(char *height);
char *get_color(char *color);
void malloc_tetrimino_struct(tetris_t *tetris);
void malloc_tetrimino_without_space(tetris_t *tetris);
int malloc_file_array(tetris_t *tetris);
int fill(tetris_t *tetris, int l, int k, int i);
void print_keys(tetris_t *tetris);
void print_infos(tetris_t *tetris);
void print_tetriminos(tetris_t *tetris, int i);
void check_arg(char **argv, int argc);
void check_arg_two(int argc, char **argv);
void check_arg_three(int argc, char **argv);
char *get_env(char **env);
int check_env(char **env);
void check_args_four(int argc, char **argv);
void check_args_five(int argc, char **argv);
void check_args_six(int argc, char **argv);
void check_args_seven(int argc, char **argv);
void check_args_eight(int argc, char **argv);
void check_args_nine(int argc, char **argv);
void check_args_ten(int argc, char **argv);
void check_args_eleven(int argc, char **argv);
void check_args_twelve(int argc, char **argv);
void check_args_thirteen(int argc, char **argv);
int check_error(solver_t *solver);

static void (*ptr1[9])(va_list) = {
    &display_int,
    &display_int,
    &convert_to_octo,
    &convert_to_hexa,
    &convert_to_mhexa,
    &display_char,
    &display_string,
    &convert_to_bin,
    &display_percentage,
};
#endif
