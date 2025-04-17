/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** my_unsetenv.c
*/

#include "my.h"

static int my_unsetenv2(linked_mysh_t *ptr, char **command,
    linked_mysh_t *prev)
{
    char *search = NULL;

    for (size_t i = 1; command[i]; i++) {
        search = my_strcat(command[i], "=");
        if (my_strncmp(ptr->env, search, my_strlen(search)) == SUCCESS) {
            prev->next = ptr->next;
            free(ptr->env);
            free(ptr);
            free(search);
            return SUCCESS;
        }
        if (my_strcmp(command[1], "*") == SUCCESS) {
            free(search);
            return SUCCESS;
        }
    }
    free(search);
    return ERROR;
}

int my_unsetenv(linked_mysh_t *ptr, char **command)
{
    linked_mysh_t *prev = NULL;

    if (command[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        free_array(command);
        return SUCCESS;
    }
    while (ptr != NULL) {
        if (my_unsetenv2(ptr, command, prev) == SUCCESS) {
            free_array(command);
            return SUCCESS;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    free_array(command);
    return SUCCESS;
}
