/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include "../include/my.h"

void fill_tetris_without_space(tetris_t *tetris)
{
    int k = 0;
    int l = 0;
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        k = 0;
        l = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (; k < tetris->tetrimino[i].height; k++) {
                l = fill(tetris, l, k, i);
            }
        }
    }
}

void sort(char **s, int n, tetris_t *tetris)
{
    int i, j, cmp;
    char *tmp = malloc(sizeof(char) * 20);

    if (n <= 1)
        return;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            cmp = my_strcmp(tetris->register_tetrimino_file[j],
            tetris->register_tetrimino_file[j+1]);
            if (cmp > 0) {
                my_strcpy(tmp, tetris->register_tetrimino_file[j+1]);
                my_strcpy(tetris->register_tetrimino_file[j+1],
                tetris->register_tetrimino_file[j]);
                my_strcpy(tetris->register_tetrimino_file[j], tmp);
            }
        }
    }
}

void init_debug_mode(tetris_t *tetris)
{
    my_printf("*** DEBUG MODE ***\n");
    print_keys(tetris);
    print_infos(tetris);
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        my_printf("Tetriminos : Name %s :", tetris->name_tetrimino[i]);
        print_tetriminos(tetris, i);
    }
    my_printf("Press any key to start Tetris\n");
    set_read_mode(1);
    read(0, stdout, 10);
    set_read_mode(0);
}

int norm_case(char **argv, tetris_t *tetris, int c)
{
    switch (c) {
        case 'L':
        if (check_level(tetris, optarg) == 84)
            display_error();
        break;
        case 'l': replace_keyleft(optarg, tetris); break;
        case 'r': replace_keyright(optarg, tetris); break;
        case 't': replace_keyturn(optarg, tetris); break;
        case 'd': replace_keydrop(optarg, tetris); break;
        case 'q': replace_keyquit(optarg, tetris); break;
        case 'p': replace_keypause(optarg, tetris); break;
        case 'w': tetris->next_tetris = 0; break;
        case 'm':
        if (check_map_size(tetris, optarg) == 84) display_error(); break;
        case 'D': tetris->init_debug = 1; break;
        case '?': display_error(); break;
        case 'h': display_help(argv[0]); break;
        default: break;
    }
}

int main(int argc, char **argv, char **env)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    int digit_optind = 0;
    tetris->init_debug = 0;
    char *term;
    int c;
    check_all_args(argc, argv);
    if (check_env(env) == 84 || (!(term = get_env(env))))
        display_error();
    create_teriminos(tetris);
    optind = 0;
    const char *flag = "-L:-l:-r:-t:-d:-q:-p:-m:-wDh";
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        c = getopt_long(argc, argv, flag, long_options, NULL);
        if (c == -1)
            break;
        norm_case(argv, tetris, c);
    }
    display_debug_bind(tetris);
}