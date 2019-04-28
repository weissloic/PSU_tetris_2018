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
        ioctl(0, TCGETS, &term);
        ioctl(0, TCGETS, &termsave);
        term.c_lflag &= ~ECHO;
        term.c_lflag &= ~ICANON;
        term.c_cc[VMIN] = 0;
        term.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, &term);
    } else
    ioctl(0, TCSETS, &termsave);
}

void sort(char **s, int n, tetris_t *tetris)
{
    int i, j, cmp;
    char tmp[10];

    if (n <= 1)
        return;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            cmp = my_strcmp(s[j], s[j+1]);
            if (cmp > 0) {
                my_strcpy(tmp, s[j+1]);
                my_strcpy(s[j+1], s[j]);
                my_strcpy(s[j], tmp);
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

int main(int argc, char **argv, char **env)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    int c;

    int digit_optind = 0;
    int init_debug = 0;

        char *term;

        check_arg(argv, argc);
        check_arg_two(argc, argv);
        check_arg_three(argc, argv);


    if (check_env(env) == 84 || (!(term = get_env(env)))) {
        write(2, "ERROR\n", 7);
        exit(84);
    }

    init_keybinding(tetris);

    const char *flag="-L:-l:-r:-t:-d:-q:-p:-m:-wDh";
    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);

    for (int k = 0;k != tetris->get_number_tetrimino; k++) {
        tetris->strcat_register_tetrimino_file[k] = 
        my_strcat1("tetriminos/", tetris->register_tetrimino_file[k]);
    }

    tetris->tetrimino = malloc(sizeof(tetrimino_t) * 
    tetris->get_number_tetrimino);
    put_error_value_to_null(tetris);
    if (open_txt(tetris) == 84)
        return (84);
    check_first_line(tetris);
    malloc_tetrimino_struct(tetris);
    get_form_tetrimino(tetris);
    malloc_tetrimino_without_space(tetris);
    check_error_tetrimino(tetris);
    fill_tetris_without_space(tetris);

    optind = 0;
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        c = getopt_long(argc, argv, flag, long_options, NULL);

        if (c == -1)
            break;

        switch (c) {
            case 'L':
            if (check_level(tetris, optarg) == 84) {
                write(2, "ERROR\n", 7);
                write(1, "ERROR\n", 7);
                exit(84);
            }
            break;
            case 'l': replace_keyleft(optarg, tetris); break;
            case 'r': replace_keyright(optarg, tetris); break;
            case 't': replace_keyturn(optarg, tetris); break;
            case 'd': replace_keydrop(optarg, tetris); break;
            case 'q': replace_keyquit(optarg, tetris); break;
            case 'p': replace_keypause(optarg, tetris); break;
            case 'w': tetris->next_tetris = 0; break;
            case 'm':
            if (check_map_size(tetris, optarg) == 84) {
                write(2, "ERROR\n", 7);
                write(1, "ERROR\n", 7);
                exit(84);
            }
            break;
            case 'D': init_debug = 1; break;
            case '?': 
                write(2, "ERROR\n", 7);
                write(1, "ERROR\n", 7);
                exit(84); break;
            case 'h': display_help(argv[0]); break;
            default: break;
        }
    }
    register_binding(tetris);
    if (check_binding(tetris) == 84) {
        write(2, "ERROR\n", 7);
        write(1, "ERROR\n", 7);
        exit(84);
    }
    if (init_debug == 1) {
        init_debug_mode(tetris);
        init_debug = 0;
   }
}