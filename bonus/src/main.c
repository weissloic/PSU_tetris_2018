/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

typedef struct hendek_s {
    int width;
    int height;
    int color;
    char *nom;
    int value_rand;
    char **register_tetris;
    char *c_width;
    char *c_height;
    char *c_color;
    char *askname;
    char *asknamecat;
} hendek_t;


int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *my_itc(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

int ask_height(hendek_t *hendek)
{
    printf("Entrez la longeur voulu !\n");
    scanf("%d", &hendek->width);
    hendek->c_width = my_itc(hendek->width);
}

int ask_width(hendek_t *hendek)
{
    printf("A présent entrez la largeur !\n");
    scanf("%d", &hendek->height);
    hendek->c_height = my_itc(hendek->height);
}

int ask_color(hendek_t *hendek)
{
    printf("Et pour finir la couleur mon amour(Compris entre 0 et 7)\n");
    scanf("%d", &hendek->color);

    if (hendek->color > 7 || hendek->color < 0) {
        printf("\nCe gag était TI-TA-NESQUE, je t'ai dit entre 1 et 7, wallah je vais te crosser\n");
        ask_color(hendek);
        return;
    }
    hendek->c_color = my_itc(hendek->color);
}

int ask_info(hendek_t *hendek)
{
    hendek->height = 0;
    hendek->width = 0;
    hendek->color = 0;

    hendek->nom = malloc(sizeof(char) * 20);
    ask_height(hendek);
    printf("Vous avez entré la longeur suivante : %d\n\n", hendek->width);

    ask_width(hendek);

    printf("Vous avez entré la largeur suivante : %d\n\n", hendek->height);

    ask_color(hendek);

    printf("Récapitulatif : largeur %d | longeur %d | couleur %d \n\n", hendek->width, hendek->height, hendek->color);

    ask_good_or_not(hendek);
}

int ask_good_or_not(hendek_t *hendek)
{
    printf("Tu es bon ? (O, Oui, N, Non)\n");
    scanf("%s", hendek->nom);
    if (my_strcmp(hendek->nom, "O") == 0 || my_strcmp(hendek->nom, "Oui") == 0) {
        true_ask(hendek);
    }
    else if (my_strcmp(hendek->nom, "N") == 0 || my_strcmp(hendek->nom, "Non") == 0) {
        false_ask(hendek);
        return;
    }
    else {
        ask_good_or_not(hendek);
        return;
    }
}

int false_ask(hendek_t *hendek)
{
    int change = 0;
    printf("Tu veux changer quoi ?\n");

    printf("1.largeur\n2.longuer\n3.couleur\n");
    scanf("%d", &change);

    if (change == 1) {
        ask_height(hendek);
        printf("\nRécapitulatif : largeur %d | longeur %d | couleur %d \n\n", hendek->width,hendek->height,hendek->color);
        ask_good_or_not(hendek);
    }
    else if (change == 2) {
        ask_width(hendek);
        printf("\nRécapitulatif : largeur %d | longeur %d | couleur %d \n\n", hendek->width,hendek->height,hendek->color);
        ask_good_or_not(hendek);
    }
    else if (change == 3) {
        ask_color(hendek);
        printf("\nRécapitulatif : largeur %d | longeur %d | couleur %d \n\n", hendek->width,hendek->height,hendek->color);
        ask_good_or_not(hendek);
    }
    else {
        false_ask(hendek);
        return;
    }
}

void malloc_my_tetrimino(hendek_t *hendek)
{
    hendek->register_tetris = malloc(sizeof(char *) * (hendek->height));

    for (int i = 0;  i <= hendek->height; i++)
        hendek->register_tetris[i] = malloc(sizeof(char) * (hendek->width));

    hendek->askname = malloc(sizeof(char) * 100);
    hendek->asknamecat = malloc(sizeof(char) * 100);

}

void fill_array(hendek_t *hendek)
{

    int i = 0;
    int o = 0;
    for (; i != my_strlen(hendek->c_width); i++) {
        hendek->register_tetris[0][i] = hendek->c_width[i];
    }

    hendek->register_tetris[0][i] = ' ';
    i += 1;

    for (int y = 0; y != my_strlen(hendek->c_height); y++) {
        hendek->register_tetris[0][i] = hendek->c_height[o];
        o++;
        i++;
    }

    hendek->register_tetris[0][i] = ' ';
    i += 1;

    for (int y = 0; y != my_strlen(hendek->c_color); y++) {
        hendek->register_tetris[0][i] = hendek->c_color[y];
        i++;
    }
}

void fill_random(hendek_t *hendek)
{
    int random_value = 0;

    for (int i = 1; i <= hendek->height; i++) {
        for (int j = 0; j != hendek->width; j++) {
            random_value = rand() % 2;
            if (random_value == 0) {
                hendek->register_tetris[i][j] = '*';
            }
            else if (random_value == 1) {
                hendek->register_tetris[i][j] = ' ';
            }
        }
    }
}

void print_array(hendek_t *hendek)
{
    for (int j = 0; j <= hendek->height; j++)
        printf("%s\n", hendek->register_tetris[j]);
}

void check_stars(hendek_t *hendek)
{
    int j = 0;
    int counter = 0;

    for (int i = 1; i <= hendek->height; i++) {
        counter = 0;
        for (j = 0; j != hendek->width; j++) {
            if (hendek->register_tetris[i][j] == '*')
                counter++;
        }
        if (counter == 0) {
            j = my_strlen(hendek->register_tetris[i]) - 1;
            hendek->register_tetris[i][j] = '*';
        }
    }
}

void check_stars_first(hendek_t *hendek)
{
    int j = 0;
    int counter = 0;
    int o = 0;

    for (int i = 1; i <= hendek->height; i++) {
        counter = 0;
        o = 0;
        for (j = 0; j != hendek->width; j++) {
            if (hendek->register_tetris[i][0] == ' ')
                counter++;
            o = (my_strlen(hendek->register_tetris[i]) - 1);
            if (hendek->register_tetris[i][o] == ' ')
                hendek->register_tetris[i][o] = '\0';
        }
        if (counter == hendek->height) {
            hendek->register_tetris[hendek->height - 1][0] = '*';
        }
    }
}

int true_ask(hendek_t *hendek)
{
    malloc_my_tetrimino(hendek);
    fill_array(hendek);
    printf("\n");
    fill_random(hendek);
    check_stars(hendek);
    check_stars_first(hendek);
    print_array(hendek);

    printf("\033[34;01mDonne un petit nom a ton tetrimino ex:(Tanguy<3lemeilleurA.E.R)\033[00m\n");
    scanf("%s", hendek->askname);

    hendek->asknamecat = my_strcat(hendek->askname, ".tetrimino");

    FILE *fp;
    fp = fopen(hendek->asknamecat , "w");

    for (int i = 0; i <= hendek->height; i++) 
        fprintf(fp, "%s\n", hendek->register_tetris[i]);

    fclose(fp);
    return(0);
}

int main(int ac, char **av)
{
    hendek_t *hendek = malloc(sizeof(hendek_t));

    srand(getpid() * time(NULL));
    printf ("\033[34;01mSalem Khey, Bienvenue dans le générateur de tetrimino !\033[00m\n\n");
    ask_info(hendek);
}