/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"

int size_line(char const *str)
{
    int n = 0;
    int nb_line = 0;

    while (str[n] != '\0') {
        if (str[n] == '\n')
            nb_line++;
        n++;
    }
    return (nb_line);
}

int condition(char c)
{
    if (c != '\t' && c != '\0' && c != '\n')
        return (1);
    return (0);
}

int display_help(void)
{
    /*int fd;
    int size;
    char buff[730];
    buff[729] = '\0';
    fd = open("help", O_RDONLY);
    if (fd < 0)
        return (84);
    size = read(fd, buff, sizeof(buff));
    if (size <= 0)
        return (84);
    my_printf("%s\n", buff);
    close(fd);
    return (0);*/

    char *s;
    int fd = open("help", O_RDONLY);
    while (s = get_next_line(fd)) {
        printf("%s\n", s);
        free(s);
    }
}

int count_line_return(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            counter++;
    }
    return (counter);
}

int get_size_file(tetris_t *tetris)
{
    struct stat fichier;
    int counter_size = 0;
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        stat(tetris->strcat_register_tetrimino_file[i], &fichier);
        if (fichier.st_size <= 2)
            tetris->tetrimino[i].error_detected = 1;
        counter_size += fichier.st_size;
    }
    return (counter_size);
}

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
                l = 0;
            }
        }
    }
}

int check_letter_str(char *str)
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '*' && str[i] != '\n' && str[i] != '\0')
            counter++;
    }
    return (counter);
}

void get_form_tetrimino(tetris_t *tetris)
{
    int j;
    int o = 0;

    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        j = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (int k = 1; tetris->tetrimino[i].tetrimino[k] != NULL; k++) {
                tetris->tetrimino[i].form_tetrimino[j] = tetris->tetrimino[i].tetrimino[k];
                j++;
            }
        }
    }
}

int check_stars_line(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '*')
            counter++;

    return (counter);
}

void check_error_tetrimino(tetris_t *tetris)
{
    int k = 0;
    int counter = 0;
    int counter_space = 0;
    int counter_false_letter = 0;
    int max_lenght = 0;
    int check_len = 0;

    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        counter = 0;
        counter_space = 0;
        counter_false_letter = 0;
        check_len = 0;
        if (tetris->tetrimino[i].error_detected == 0) {
            for (int j = 0; j != tetris->tetrimino[i].height; j++) {
                max_lenght = 0;

                if (check_letter_str(tetris->tetrimino[i].form_tetrimino[j]) != 0)
                    counter_false_letter++;
                if ((tetris->tetrimino[i].form_tetrimino[j][0] == ' ' && (check_stars_line(tetris->tetrimino[i].form_tetrimino[j]) > 0))
                    || tetris->tetrimino[i].form_tetrimino[j][0] == '*') {
                    counter++;
                }
                if (tetris->tetrimino[i].form_tetrimino[j][0] == ' ')
                    counter_space++;

                max_lenght = my_strlen(tetris->tetrimino[i].form_tetrimino[j]);
                if (max_lenght == tetris->tetrimino[i].width)
                    check_len++;
            }

            if (check_len == 0)
                tetris->tetrimino[i].error_detected = 1;

            if (counter != tetris->tetrimino[i].height ||
                counter_space == tetris->tetrimino[i].height ||
                counter_false_letter != 0 ||
                tetris->tetrimino[i].color > 7)
                tetris->tetrimino[i].error_detected = 1;
        }
    }
}

int open_txt(tetris_t *tetris)
{
    char **register_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (int i = 0; i != tetris->get_number_tetrimino; i++)
        register_file[i] = malloc(sizeof(char) * get_size_file(tetris));

    int fd;
    int size;

    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        if (tetris->tetrimino[k].error_detected == 0) {
        fd = open(tetris->strcat_register_tetrimino_file[k], O_RDONLY);
        if (fd < 0)
            tetris->tetrimino[k].error_detected == 1;
        size = read(fd, register_file[k], (get_size_file(tetris)));
        if (size <= 0)
            tetris->tetrimino[k].error_detected == 1;
    }
    }
    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        if (tetris->tetrimino[k].error_detected == 0)
            tetris->tetrimino[k].tetrimino = my_str_to_word_array(register_file[k]);
    }
    return (0);
}

void put_error_value_to_null(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        tetris->tetrimino[i].error_detected = 0;
    }
}

int check_first_line(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        if (tetris->tetrimino[i].error_detected == 0) {

            if (tetris->tetrimino[i].tetrimino[0][0] == '\0')
                tetris->tetrimino[i].error_detected = 1;
            else if (count_space_str(tetris->tetrimino[i].tetrimino[0]) >= 2  && (tetris->tetrimino[i].tetrimino[0][0] >= '0' &&
                tetris->tetrimino[i].tetrimino[0][0] <= '9')
                && my_str_isnum2(tetris->tetrimino[i].tetrimino[0]) == 1 && tetris->tetrimino[i].error_detected == 0) {
                get_number_first_line(tetris, i);
            }
            else
                tetris->tetrimino[i].error_detected = 1;
        }
    }
}

int count_space_str(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            counter++;
    }
    return (counter);
}

void            set_read_mode(int mode)
{
  static struct termios termsave;
  static struct termios term;

  if (mode == 1)
    {
      ioctl(0, TCGETS, &term);
      ioctl(0, TCGETS, &termsave);
      term.c_lflag &= ~ECHO;
      term.c_lflag &= ~ICANON;
      term.c_cc[VMIN] = 1;
      term.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &term);
    }
  else if (mode == 2)
    {
      ioctl(0, TCGETS, &term);
      ioctl(0, TCGETS, &termsave);
      term.c_lflag &= ~ECHO;
      term.c_lflag &= ~ICANON;
      term.c_cc[VMIN] = 0;
      term.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &term);
    }
  else
    ioctl(0, TCSETS, &termsave);
}

/*int main (int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));


    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);

    for (int k = 0;k != tetris->get_number_tetrimino; k++) {
        tetris->strcat_register_tetrimino_file[k] = my_strcat1("tetriminos/", tetris->register_tetrimino_file[k]);
         //my_printf("%s\n", tetris->strcat_register_tetrimino_file[k]);
    }
    tetris->tetrimino = malloc(sizeof(tetrimino_t) * tetris->get_number_tetrimino);

    open_txt(tetris);
    put_error_value_to_null(tetris);
    check_first_line(tetris);
    malloc_tetrimino_struct(tetris);
    get_form_tetrimino(tetris);
    malloc_tetrimino_without_space(tetris);
    check_error_tetrimino(tetris);
    fill_tetris_without_space(tetris);

    init_debug_mode(tetris);



    //freeArray(tetris->strcat_register_tetrimino_file, tetris->get_number_tetrimino);
    //freeArray(tetris->name_tetrimino, tetris->get_number_tetrimino);
    //freeArray(tetris->register_tetrimino_file, 8);
}*/

void freeArray(char **a, int m)
{
    int i;
    for (i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}

void sort(char **s,int n, tetris_t *tetris)
{
    int i = 0;
    int j = 0;
    int cmp = 0;
    char tmp[0][tetris->get_number_tetrimino];

    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++) {
            cmp = my_strcmp(s[j], s[j+1]);
            if (cmp > 0) {
                my_strcpy(tmp[0], s[j+1]);
                my_strcpy(s[j+1], s[j]);
                my_strcpy(s[j], tmp[0]);
            }   
        }
}


int get_number_file(tetris_t *tetris)
{
    DIR *rep = opendir("tetriminos/");
    tetris->get_number_tetrimino = 0;
    tetris->get_max_size = 0;
    int i = 0;
    int pos = 0;

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            pos = my_strlen(ent->d_name) - 10;
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~' && !(my_strcmp(&ent->d_name[pos], ".tetrimino"))) {
                tetris->get_number_tetrimino++;
            if (my_strlen(ent->d_name) > tetris->get_max_size)
                tetris->get_max_size = my_strlen(ent->d_name);
            }
        }
    closedir (rep);
    }
    return 0;
}

int reopen_get_number_file(tetris_t *tetris)
{
    DIR *rep = opendir("tetriminos/");
    int i = 0;
    int j = 0;
    int pos = 0;

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            pos = my_strlen(ent->d_name) - 10;
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~' && !(my_strcmp(&ent->d_name[pos], ".tetrimino"))) {
                tetris->register_tetrimino_file[i] = ent->d_name;
                i++;
            }
        }
    closedir (rep);
    }
    return 0;
}

void init_debug_mode(tetris_t *tetris)
{

    char *space = "(space)";
    char *yes = "Yes";
    char *no = "No";
    my_printf("*** DEBUG MODE ***\n");
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
    read(0, NULL, 10);
    set_read_mode(0);
}

int check_map_size(tetris_t *tetris, char *optarg)
{
    int counter_star_char_map = 0;
    char *contain_row = malloc(sizeof(char) * 4);
    char *contain_col = malloc(sizeof(char) * 4);
    int fill_contain_row_col = 0;
    int fill_contain = 0;
    int valid_string = 0;

    for (int i = 0; optarg[i] != '\0'; i++) {
        if ((optarg[i] < '0' || optarg[i] > '9') && optarg[i] != ',')
            valid_string = 1;
        if (optarg[i] == ',')
            counter_star_char_map += 1;
    }

    if (counter_star_char_map == 1 && valid_string == 0) {
        for (fill_contain_row_col; optarg[fill_contain_row_col] != ','; fill_contain_row_col++)
            contain_row[fill_contain_row_col] = optarg[fill_contain_row_col];

        for (fill_contain_row_col; optarg[fill_contain_row_col + 1] != '\0'; fill_contain_row_col++) {
            contain_col[fill_contain] = optarg[fill_contain_row_col + 1];
            fill_contain++;
        }
    }
        tetris->map_size_row = my_atoi(contain_row);
        tetris->map_size_col = my_atoi(contain_col);

        if (tetris->map_size_row <= 0 || tetris->map_size_col <= 0)
            return 84;
}

int check_level(tetris_t *tetris, char *optarg)
{
    int bool_letter_level = 0;

    for (int i = 0; optarg[i] != '\0'; i++) {
        if (optarg[i] >= '0' && optarg[i] <= '9')
            bool_letter_level = 1;
    }
    if (bool_letter_level == 1)
        tetris->level_num = my_atoi(optarg);
    else {
        my_printf("WRONG LEVEL\n");
        return (84);
    }
}

int main(int argc, char **argv)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    int c;
    init_keybinding(tetris);
    int digit_optind = 0;
    int init_debug = 0;

    const char *flag="L:l:r:t:d:q:p:m:wDh";

    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
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
           if (check_level(tetris, optarg) == 84)
            return (84);
           break;
           case 'l': if (replace_keyleft(optarg, tetris) == 84) return 84; break;
           case 'r': if (replace_keyright(optarg, tetris) == 84) return 84; break;
           case 't': if (replace_keyturn(optarg, tetris) == 84) return 84; break;
           case 'd': if (replace_keydrop(optarg, tetris) == 84) return 84; break;
           case 'q': if (replace_keyquit(optarg, tetris) == 84) return 84; break;
           case 'p': if (replace_keypause(optarg, tetris) == 84) return 84; break;
           case 'w': tetris->next_tetris = 0; break;
           case 'm':
            if (check_map_size(tetris, optarg) == 84)
                return 84;
            break;
           case 'D': init_debug = 1; break;
           case 'h': return (display_help());; break;
           default: printf("RETURN 84\n");
        }
    }
    register_binding(tetris);
    if (check_binding(tetris) == 84)
        return (84);
   if (init_debug == 1) {
        init_debug_mode(tetris);
        init_debug = 0;
   }
}