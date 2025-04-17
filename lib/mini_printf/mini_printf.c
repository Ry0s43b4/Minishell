/*
** EPITECH PROJECT, 2024
** B-CPE-101-PAR-1-3-miniprintf-nicky.truong
** File description:
** main.c
*/

#include "my.h"

static void check_percent(char const *format, va_list flag)
{
    int i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            check_flag(format, flag, i);
            i++;
        } else
            my_putchar(format[i]);
        i++;
    }
}

int mini_printf(const char *format, ...)
{
    va_list flag;

    va_start(flag, format);
    check_percent(format, flag);
    va_end(flag);
    return 0;
}
