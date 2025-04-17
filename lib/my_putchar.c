/*
** EPITECH PROJECT, 2024
** My putchar
** File description:
** Function that will write characters 1 by 1
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
