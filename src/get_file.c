/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"


int display_help(void)
{
    int fd;
    int size;
    char buff[760];
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

int main (int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    get_number_file(tetris);
    malloc_file_array(tetris);
    reopen_get_number_file(tetris);
    sort(tetris->register_tetrimino_file, tetris->get_number_tetrimino, tetris);
    get_name(tetris);

    for (int k = 0; k != tetris->get_number_tetrimino; k++)
        printf("%s\n", tetris->register_tetrimino_file[k]);

    for (int k = 0;k != tetris->get_number_tetrimino; k++)
        printf("%s\n", tetris->name_tetrimino[k]);
}

void sort(char **s,int n, tetris_t *tetris)
{
    int i = 0;
    int j = 0;
    int cmp = 0;
    char tmp[0][tetris->get_number_tetrimino];

    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++) {
            cmp = my_strcmp(s[j], s[j+1s]);
            if (cmp > 0) {
                my_strcpy(tmp[0], s[j+1]);
                my_strcpy(s[j+1], s[j]);
                my_strcpy(s[j], tmp[0]);
            }   
        }
}


int get_number_file(tetris_t *tetris)
{
    DIR *rep = opendir("test_tetris/");
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
    DIR * rep = opendir("test_tetris/");
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

    tetris->register_tetrimino_file = malloc(sizeof(char *) * tetris->get_number_tetrimino);
    tetris->name_tetrimino = malloc(sizeof(char *) * tetris->get_number_tetrimino);

    for (i; i != tetris->get_number_tetrimino; i++)
        tetris->register_tetrimino_file[i] = malloc(sizeof(char) * tetris->get_max_size);

    for (j; j != tetris->get_number_tetrimino; j++)
        tetris->name_tetrimino[j] = malloc(sizeof(char) * (tetris->get_max_size - 10));

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

static int  is_max(char *str, int iterator)
{
  char      *max;
  int       iterator2;

  max = "2147483648";
  iterator2 = 0;
  while (iterator2 <= 9)
    {
      if (str[iterator + iterator2] != max[iterator2])
    return (0);
      iterator2 += 1;
    }
  return (1);
}

static int  get_sign(char *str, int *iterator, int *is_neg)
{
  while (!('0' <= str[*iterator] && str[*iterator] <= '9'))
    {
      if (str[*iterator] != '+' && str[*iterator] != '-')
    return (0);
      if (str[*iterator] == '-')
    {
      if (*is_neg == 0)
        *is_neg = 1;
      else
        *is_neg = 0;
    }
      *iterator += 1;
    }
  return (0);
}

int my_getnbr1(char *str)
{
  int   iterator;
  int   nbr;
  int   is_neg;

  is_neg = 0;
  iterator = 0;
  nbr = 0;
  get_sign(str, &iterator, &is_neg);
  if (is_max(str, iterator))
    return (-2147483648);
  while ('0' <= str[iterator] && str[iterator] <= '9')
    {
      nbr = nbr * 10 + str[iterator] - 48;
      if (nbr < 0)
    return (0);
      iterator += 1;
    }
  if (is_neg)
    nbr *= -1;
  return (nbr);
}

int my_str_isnum1(char *str)
{
  int   i;
  int   is_alpha;

  is_alpha = 1;
  i = -1;
  while (str[(i = i + 1)] != '\0')
    if (!(str[i] < 47 && str[i] > 58))
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