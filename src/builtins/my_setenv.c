/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** my_setenv.c
*/

#include "my.h"

static int search_in_env(linked_mysh_t *ptr, char *name)
{
    char *search = my_strcat(name, "=");

    for (linked_mysh_t *tmp = ptr; tmp; tmp = tmp->next)
        if (my_strncmp(tmp->env, search, my_strlen(search)) == SUCCESS) {
            free(search);
            return SUCCESS;
        }
    free(search);
    return ERROR;
}

static linked_mysh_t *modify_env(linked_mysh_t *ptr, char **command)
{
    linked_mysh_t *line = NULL;
    char *search = my_strcat(command[1], "=");

    for (linked_mysh_t *tmp = ptr; tmp; tmp = tmp->next)
        if (my_strncmp(tmp->env, search, my_strlen(search)) == SUCCESS)
            line = tmp;
    free(line->env);
    if (command[2] == NULL)
        line->env = my_strdup(search);
    else
        line->env = my_strcat(search, command[2]);
    free(search);
    return ptr;
}

static linked_mysh_t *add_setenv(linked_mysh_t *ptr, char **command, int args)
{
    char *tmp = NULL;
    char *tmp2 = NULL;

    if (args == 2) {
        tmp = my_strcat(command[1], "=");
        ptr = add_node_to_list(ptr, tmp);
    }
    if (args == 3) {
        tmp = my_strcat(command[1], "=");
        tmp2 = my_strcat(tmp, command[2]);
        ptr = add_node_to_list(ptr, tmp2);
        free(tmp2);
    }
    free(tmp);
    free_array(command);
    return ptr;
}

static int check_setenv(char **command)
{
    if (command[1] == NULL)
        return SUCCESS;
    if ((command[1][0] >= 'A' && command[1][0] <= 'Z'))
        return SUCCESS;
    if (command[1][0] >= 'a' && command[1][0] <= 'z')
        return SUCCESS;
    if (command[1][0] == '_')
        return SUCCESS;
    write(2, "setenv: Variable name must begin with a letter.\n", 48);
    free_array(command);
    return ERROR;
}

static int check_setenv2(linked_mysh_t *ptr, char **command, int args)
{
    if (args > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        free_array(command);
        return SUCCESS;
    }
    if (args == 1 && command[1] == NULL) {
        display_env(ptr, command);
        return SUCCESS;
    }
    if (search_in_env(ptr, command[1]) == SUCCESS) {
        ptr = modify_env(ptr, command);
        free_array(command);
        return SUCCESS;
    }
    return ERROR;
}

static int valid_setenv(char **command)
{
    if (command[1] == NULL)
        return SUCCESS;
    for (size_t i = 0; command[1][i] != '\0'; ++i) {
        if (command[1][i] >= 'A' && command[1][i] <= 'Z')
            continue;
        if (command[1][i] >= 'a' && command[1][i] <= 'z')
            continue;
        if (command[1][i] >= '0' && command[1][i] <= '9')
            continue;
        else {
            write(2, "setenv: Variable name must contain alphanumeric"
            " characters.\n", 60);
            free_array(command);
            return ERROR;
        }
    }
    return SUCCESS;
}

int my_setenv(linked_mysh_t *ptr, char **command)
{
    int args = 0;

    if (valid_setenv(command) == ERROR)
        return SUCCESS;
    if (check_setenv(command) == ERROR)
        return SUCCESS;
    for (; command[args]; args++);
    if (check_setenv2(ptr, command, args) == SUCCESS)
        return SUCCESS;
    else
        ptr = add_setenv(ptr, command, args);
    return SUCCESS;
}
