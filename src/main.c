/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** main.c
*/

#include "my.h"

static linked_mysh_t *copy_env(linked_mysh_t *ptr, char **env)
{
    size_t lines = 0;

    for (; env[lines] != NULL; ++lines);
    for (size_t i = 0; i < lines; ++i)
        ptr = add_node_to_list(ptr, env[i]);
    return ptr;
}

int main(int ac, char **, char **env)
{
    linked_mysh_t *ptr = NULL;

    if (ac > 1)
        return ERROR;
    ptr = copy_env(ptr, env);
    return loop(ptr);
}
