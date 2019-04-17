/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i <= n; i++) {
        dest[i] = src[i];
        if (n == i)
            dest[n] = '\0';
    }
    return (dest);
}

int size_line(char const *str)
{
    int n = 0;
    int nb_line = 0;

    while (str[n] != 0) {
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

char **my_str_to_word_array(char const *buffer)
{
    char **word_array;
    int n = 0;
    int x = 0;
    int y = 0;

    word_array = malloc(sizeof(char *) * (size_line(buffer) + 1));
    while (buffer[y] != '\0') {
        for (x = 0; condition(buffer[x + y]); x++);
        if (x != 0) {
            word_array[n] = malloc(sizeof(char) * x + 1);
            my_strncpy(word_array[n], buffer + y, x);
            word_array[n][x] = '\0';
            n++;
            y += x;
        }
        if (buffer[y] != '\0')
            y++;
    }
    word_array[n] = NULL;
    return (word_array);
}

int display_help(void)
{
    int fd;
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
    return (0);
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
        counter_size += fichier.st_size;
    }
    return (counter_size);
}


void malloc_tetrimino_struct(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        if (tetris->tetrimino[i].error_detected == 0) {
            tetris->tetrimino[i].form_tetrimino = malloc(sizeof(char *) * tetris->tetrimino[i].height);
            for (int k = 0; k != tetris->tetrimino[i].height; k++) {
                tetris->tetrimino[i].form_tetrimino[k] = malloc(sizeof(char) * tetris->tetrimino[i].width);
            }
        }
    }
}

void get_form_tetrimino(tetris_t *tetris)
{
    int j;

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

int open_txt(tetris_t *tetris)
{
    char **register_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (int i = 0; i != tetris->get_number_tetrimino; i++)
        register_file[i] = malloc(sizeof(char) * get_size_file(tetris));

    int fd;
    int size;

    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        fd = open(tetris->strcat_register_tetrimino_file[k], O_RDONLY);
        if (fd < 0)
            return (84);
        size = read(fd, register_file[k], (get_size_file(tetris) + 1));
        if (size <= 0)
            return (84);
        printf("%s\n", register_file[k]);
    }
    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        tetris->tetrimino[k].tetrimino = my_str_to_word_array(register_file[k]);
    }
    put_error_value_to_null(tetris);
    check_first_line(tetris);
    malloc_tetrimino_struct(tetris);
    get_form_tetrimino(tetris);


    for (int i = 0; i != 2; i++)
        printf("%s\n", tetris->tetrimino[1].form_tetrimino[i]);

    return (0);
}

char *get_width(char *width)
{
    int i = 0;
    char *register_width = malloc(sizeof(char) * i);

    for (; width[i] != ' '; i++) {
        register_width[i] = width[i];
    }
    return (register_width);
}

char *get_height(char *height)
{
    int k = 0;
    char *register_height = malloc(sizeof(char) * k);

    int counter = 0;

    for (int i = 0; height[i] != '\0'; i++) {
        if (height[i] == ' ') {
            counter++;
        }
        if (counter == 1) {
            register_height[k] = height[i + 1];
            k++;
        }
    }
    return (register_height);
}

char *get_color(char *color)
{
    int k = 0;
    char *register_color = malloc(sizeof(char) * k);


    int counter = 0;

    for (int i = 0; color[i] != '\0'; i++) {
        if (color[i] == ' ') {
            counter++;
        }
        if (counter == 2) {
            register_color[k] = color[i + 1];
            k++;
        }
    }
    return (register_color);
}

int my_str_isnum2(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' && str[i] > '9') || str[i] != ' ' || str[i] != '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}

void put_error_value_to_null(tetris_t *tetris)
{
    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        tetris->tetrimino[i].error_detected = 0;
    }
}

void get_number_first_line(tetris_t *tetris, int i)
{
    char *width;
    char *height;
    char *color;


    width = get_width(tetris->tetrimino[i].tetrimino[0]);
    height = get_height(tetris->tetrimino[i].tetrimino[0]);
    color = get_color(tetris->tetrimino[i].tetrimino[0]);
    tetris->tetrimino[i].width = my_getnbr(width);
    tetris->tetrimino[i].height = my_getnbr(height);
    tetris->tetrimino[i].color = my_getnbr(color);

}


int check_first_line(tetris_t *tetris)
{


    for (int i = 0; i != tetris->get_number_tetrimino; i++) {
        if (count_space_str(tetris->tetrimino[i].tetrimino[0]) == 2  && (tetris->tetrimino[i].tetrimino[0][0] >= '0' &&
            tetris->tetrimino[i].tetrimino[0][0] <= '9')
            && my_str_isnum2(tetris->tetrimino[i].tetrimino[0]) == 1) {
            get_number_first_line(tetris, i);
        }
        else
            tetris->tetrimino[i].error_detected = 1;


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

void get_name(tetris_t *tetris)
{
    int j = 0;
    int i = 0;

    for (int k = 0; k != tetris->get_number_tetrimino; k++) {
        for (j = 0; tetris->register_tetrimino_file[k][j] != '.'; j++) {
                tetris->name_tetrimino[k][j] = tetris->register_tetrimino_file[k][j];
        }
    }
}

char *my_strcat1(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (int j = 0; j < my_strlen(dest); j++)
        tmp[j] = dest[j];
    for (i = 0; i < my_strlen(src); i++)
        tmp[length + i] = src[i];
    tmp[length + i] = '\0';
    return (tmp);
}

int main (int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));


    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);

    for (int k = 0; k != tetris->get_number_tetrimino; k++)
        my_printf("%s\n", tetris->register_tetrimino_file[k]);

    for (int k = 0;k != tetris->get_number_tetrimino; k++)
        my_printf("%s\n", tetris->name_tetrimino[k]);


    for (int k = 0;k != tetris->get_number_tetrimino; k++) {
         tetris->strcat_register_tetrimino_file[k] = my_strcat1("tetriminos/", tetris->register_tetrimino_file[k]);
        my_printf("%s\n", tetris->strcat_register_tetrimino_file[k]);
      }

    tetris->tetrimino = malloc(sizeof(tetrimino_t) * tetris->get_number_tetrimino);

    open_txt(tetris);

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

    if (rep != NULL) {
        struct dirent *ent;
        while ((ent = readdir(rep)) != NULL){
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~') {
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

    if (rep != NULL) {
        struct dirent *ent;

        while ((ent = readdir(rep)) != NULL){
            if (ent->d_name[0] != '.' && ent->d_name[my_strlen(ent->d_name) - 1] != '~') {
                tetris->register_tetrimino_file[i] = ent->d_name;
                i++;
            }
        }
    closedir (rep);
    }
    return 0;
}

int malloc_file_array(tetris_t *tetris)
{
    
    int i = 0;
    int j = 0;
    int k = 0;

    tetris->register_tetrimino_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);
    tetris->name_tetrimino = malloc(sizeof(char *) * tetris->get_number_tetrimino);
    tetris->strcat_register_tetrimino_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (i; i != tetris->get_number_tetrimino; i++)
        tetris->register_tetrimino_file[i] = malloc(sizeof(char) * tetris->get_max_size);

    for (j; j != tetris->get_number_tetrimino; j++)
        tetris->name_tetrimino[j] = malloc(sizeof(char) * (tetris->get_max_size - my_strlen(".tetrimino")));

    for (k; k != tetris->get_number_tetrimino; k++)
        tetris->strcat_register_tetrimino_file[k] = malloc(sizeof(char) * (tetris->get_max_size + my_strlen("tetrimino/")));

}

void init_debug_mode(tetris_t *tetris)
{
    char *space = "(space)";
    char *yes = "Yes";
    char *no = "No";
    printf("*** DEBUG MODE ***\n");
    int left = (my_strcmp(tetris->key_left, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Left: %s\n", tetris->key_left);
    int right = (my_strcmp(tetris->key_right, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Right: %s\n", tetris->key_right);
    int turn = (my_strcmp(tetris->key_turn, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Turn: %s\n", tetris->key_turn);
    int drop = (my_strcmp(tetris->key_drop, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Drop: %s\n", tetris->key_drop);;
    int quit = (my_strcmp(tetris->key_quit, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Quit: %s\n", tetris->key_quit);
    int pause = (my_strcmp(tetris->key_pause, " ") == 0) ? printf("Key Left: %s\n", space) : printf("Key Pause: %s\n", tetris->key_pause);
    int next = tetris->next_tetris == 0 ? printf("Next: %s\n", no) : printf("Next: %s\n", yes);
    printf("Level: %d\n", tetris->level_num);
    printf("Size: %d*%d\n", tetris->map_size_row, tetris->map_size_col);
    printf("Tetriminos: %d\n", tetris->get_number_tetrimino);
}


int my_str_isnum1(char *str)
{
  int   i;
  int   is_alpha;

  is_alpha = 1;
  i = -1;
  while (str[(i = i + 1)] != '\0')
    if (!(str[i] < 47 && str[i] > 58) && str[i] != 32)
      is_alpha = 0;
  return (is_alpha);
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
        if ((optarg[i] < '0' || optarg[i] > '9') && optarg[i] != '*')
            valid_string = 1;
        if (optarg[i] == '*')
            counter_star_char_map += 1;
    }

    if (counter_star_char_map == 1 && valid_string == 0) {
        for (fill_contain_row_col; optarg[fill_contain_row_col] != '*'; fill_contain_row_col++)
            contain_row[fill_contain_row_col] = optarg[fill_contain_row_col];

        for (fill_contain_row_col; optarg[fill_contain_row_col + 1] != '\0'; fill_contain_row_col++) {
            contain_col[fill_contain] = optarg[fill_contain_row_col + 1];
            fill_contain++;
        }
    }
        tetris->map_size_row = my_getnbr(contain_row);
        tetris->map_size_col = my_getnbr(contain_col);

        if (tetris->map_size_row <= 0 || tetris->map_size_col <= 0)
            return 84;
}

void init_keybinding(tetris_t *tetris)
{
    tetris->key_left = "^EOD";
    tetris->key_right = "^EOC";
    tetris->key_turn = "(space)";
    tetris->key_drop = "x";
    tetris->key_quit = "q";
    tetris->key_pause = "p";
    tetris->level_num = 1;
    tetris->map_size_col = 20;
    tetris->map_size_row = 10;
    tetris->next_tetris = "Yes";
}

void check_level(tetris_t *tetris, char *optarg)
{
    int bool_letter_level = 0;

    for (int i = 0; optarg[i] != '\0'; i++) {
        if (optarg[i] < '0' || optarg[i] > '9')
            bool_letter_level = 1;
    }
    if (bool_letter_level == 0)
        tetris->level_num = my_getnbr(optarg);

}

/*int main(int argc, char **argv)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    int c;
    init_keybinding(tetris);
    int digit_optind = 0;
    int init_debug = 0;

    const char *flag="L:l:r:t:d:q:p:m:wDh";



    optind = 0;
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        c = getopt_long(argc, argv, flag, long_options, NULL);

        if (c == -1)
            break;

       switch (c) {
           case 'L':
           check_level(tetris, optarg);
           break;
           case 'l': printf("Paramètre l rencontré avec argument %s\n", optarg); break;
           case 'r': printf ("Paramètre r rencontré avec argument %s\n", optarg); break;
           case 't': printf("Paramètre t rencontré avec argument %s\n", optarg); break;
           case 'd': printf ("Paramètre d rencontré avec argument %s\n", optarg); break;
           case 'q': printf("Paramètre q rencontré avec argument %s\n", optarg); break;
           case 'p': printf ("Paramètre p rencontré avec argument %s\n", optarg); break;
           case 'w': tetris->next_tetris = 0; break;
           case 'm':
            //

            if (check_map_size(tetris, optarg) == 84)
                return 84;
            break;
           case 'D': init_debug = 1; break;
           case 'h': return (display_help());; break;
           default: printf("RETURN 84\n");
        }
    }
   if (init_debug == 1) {
        init_debug_mode(tetris);
        init_debug = 0;
   }
}*/