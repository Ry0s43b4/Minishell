/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** Env handling in here
*/

#include "my.h"

int display_env(linked_mysh_t *ptr, char **command)
{
    if (command[1] != NULL) {
        write(2, "Too many arguments\n", 19);
        free_array(command);
        return SUCCESS;
    }
    while (ptr != NULL) {
        my_putstr(ptr->env);
        my_putchar('\n');
        ptr = ptr->next;
    }
    free_array(command);
    return SUCCESS;
}
