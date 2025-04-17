/*
** EPITECH PROJECT, 2025
** Tests
** File description:
** File needed for the unit tests of the project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
