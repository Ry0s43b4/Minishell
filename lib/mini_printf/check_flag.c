/*
** EPITECH PROJECT, 2024
** B-CPE-101-PAR-1-3-miniprintf-nicky.truong
** File description:
** check_flag.c
*/

#include "my.h"

static void str_to_print(va_list flag)
{
    my_putstr(va_arg(flag, char *));
}

static void char_to_print(va_list flag)
{
    my_putchar((char) va_arg(flag, int));
}

static void nbr_to_print(va_list flag)
{
    my_put_nbr(va_arg(flag, int));
}

static void print_percent(va_list)
{
    my_putchar('%');
}

int check_flag(char const *format, va_list flag, int j)
{
    char all_flags[] = {'s', 'c', 'd', 'i', '%'};
    ptr_t functions[] = {str_to_print, char_to_print, nbr_to_print,
    nbr_to_print, print_percent};
    int nbr_flags = sizeof(all_flags) / sizeof(all_flags[0]);

    for (int i = 0; i < nbr_flags; i++) {
        if (format[j + 1] == all_flags[i]) {
            functions[i](flag);
            return 0;
        }
    }
    return 0;
}
