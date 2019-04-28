/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"


void fill_tetris_without_space(tetris_t *tetris)
{
    int k = 0; 
    int l = 0;
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        k = 0;
        l = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (; k < tetris->tetrimino[i].height; k++) {
                for (; l < tetris->tetrimino[i].width; l++) {
                    tetris->tetrimino[i].tetri_without_final_space[k][l] = tetris->tetrimino[i].form_tetrimino[k][l];
                }
                tetris->tetrimino[i].tetri_without_final_space[k][l] = '\0';
                l = 0;
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
            cmp = strcmp(s[j], s[j+1]);
            if (cmp > 0) {
                strcpy(tmp, s[j+1]);
                strcpy(s[j+1], s[j]);
                strcpy(s[j], tmp);
            }
        }
    }
}

void init_debug_mode(tetris_t *tetris)
{

    char *space = "(space)";
    char *yes = "Yes";
    char *no = "No";
    my_printf("*** DEBUG MODE ***\n");
    //int left2 = (my_strcmp(tetris->key_left, "\0") == 0) ? my_printf("Key Left : %s\n", "\0") : my_printf("Key Left : %s\n", "\0");
    int left = (my_strcmp(tetris->key_left, " ") == 0) ? my_printf("Key Left : %s\n", space) : my_printf("Key Left : %s\n", tetris->key_left);
    int right = (my_strcmp(tetris->key_right, " ") == 0) ? my_printf("Key Left : %s\n", space) : my_printf("Key Right : %s\n", tetris->key_right);
    int turn = (my_strcmp(tetris->key_turn, " ") == 0) ? my_printf("Key Turn : %s\n", space) : my_printf("Key Turn : %s\n", tetris->key_turn);
    int drop = (my_strcmp(tetris->key_drop, " ") == 0) ? my_printf("Key Drop : %s\n", space) : my_printf("Key Drop : %s\n", tetris->key_drop);;
    int quit = (my_strcmp(tetris->key_quit, " ") == 0) ? my_printf("Key Quit : %s\n", space) : my_printf("Key Quit : %s\n", tetris->key_quit);
    int pause = (my_strcmp(tetris->key_pause, " ") == 0) ? my_printf("Key Pause : %s\n", space) : my_printf("Key Pause : %s\n", tetris->key_pause);
    int next = tetris->next_tetris == 0 ? my_printf("Next : %s\n", no) : my_printf("Next : %s\n", yes);
    my_printf("Level : %d\n", tetris->level_num);
    my_printf("Size : %d*%d\n", tetris->map_size_row, tetris->map_size_col);
    my_printf("Tetriminos : %d\n", tetris->get_number_tetrimino);
    ///////////////AFFICHAGE TETRIMINO//////
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        my_printf("Tetriminos : Name %s :", tetris->name_tetrimino[i]);
        if (tetris->tetrimino[i].error_detected == 0) {
            my_printf(" Size %d*%d :", tetris->tetrimino[i].width, tetris->tetrimino[i].height);
            my_printf(" Color %d :", tetris->tetrimino[i].color);
            my_printf("\n");
            for (int j = 0; j != tetris->tetrimino[i].height; j++) {

                my_printf("%s\n", tetris->tetrimino[i].tetri_without_final_space[j]);
            }
        }
        else if (tetris->tetrimino[i].error_detected == 1) {
            my_printf("%s\n", " Error");
        }
    }
    my_printf("Press any key to start Tetris\n");
    set_read_mode(1);
    read(0, stdout, 10);
    set_read_mode(0);
}

int check_env(char **env)
{
    if (env == NULL || env[0] == NULL)
        return (84);
}

char *get_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++)
        if (!my_strncmp("TERM=", env[i], 4))
            return ((char *)(env[i] + 5));
    return (NULL);
}

void check_arg(char **argv, int argc)
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

void check_arg_two(int argc, char **argv)
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

void check_arg_four(int argc, char **argv)
{
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
        check_arg_four(argc, argv);


    if (check_env(env) == 84 || (!(term = get_env(env)))) {
        write(2, "ERROR\n", 7);
        exit(84);
    }

    init_keybinding(tetris);

    const char *flag="-L:-l:-r:-t:-d:-q:-p:-m:-wDh";
    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    //sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);

    for (int k = 0;k != tetris->get_number_tetrimino; k++) {
        tetris->strcat_register_tetrimino_file[k] = my_strcat1("tetriminos/", tetris->register_tetrimino_file[k]);
    }


    tetris->tetrimino = malloc(sizeof(tetrimino_t) * tetris->get_number_tetrimino);
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
           case 'l': replace_keyleft(optarg, tetris);; break;
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