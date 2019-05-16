/*
** EPITECH PROJECT, 2018
** test_infin_add.c
** File description:
** testing infin_add
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include <string.h>

int get_number_file2(void);
int replace_keyquit2(char *str);

void redirect_all_stdfour(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(file_number, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(get_number_file2(), 9);
}

Test(false_enter, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(replace_keyquit2("jkqn"), 84);
}

Test(color, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(atoi(get_color("3   4    55")), 55);
}

Test(width, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(atoi(get_width("3   4    55")), 3);
}

Test(height, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(atoi(get_height("3   4    55")), 4);
}

Test(help, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(display_helptwo(), 84);
}

Test(condition, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(condition_two('y'), 1);
}

Test(get_info, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(check_space(" "), 1);
}

Test(atoi, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(my_atoi("7443"), 7443);
}

Test(is_num, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(my_str_isnum1("3 zdq2n"), 0);
}

Test(lettre_str, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(check_letter_str("3 zdq2n"), 6);
}

Test(star, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(check_stars_line("3* zd****q2n*"), 6);
}

Test(space_str, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(count_space_strtwo("3* zd*  ***q2 n*"), 4);
}


Test(enter, testing_percentage, .init = redirect_all_stdfour)
{
    cr_assert_eq(size_line_two("3* \nzd* \n***\nq2 n*"), 3);
}




