/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my str isnum
*/

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == ' ')
            return (1);
        else
            return (0);
    }
    return (0);
}
