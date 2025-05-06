/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** error_handling.c
*/

#include "my.h"

linked_mysh_t *add_node_to_list(linked_mysh_t *ptr, char *line)
{
    linked_mysh_t *node = malloc(sizeof(linked_mysh_t));
    linked_mysh_t *tmp = ptr;

    if (node == NULL)
        return ptr;
    node->env = my_strdup(line);
    node->next = NULL;
    if (ptr == NULL)
        return node;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return ptr;
}

static char **remove_path(char *pathline)
{
    char **new_env = NULL;
    char *tmp = NULL;
    size_t len = my_strlen(pathline);
    int j = 0;

    tmp = malloc(sizeof(char) * (len - 4));
    if (tmp == NULL)
        return NULL;
    for (size_t i = 5; i < len; i++) {
        tmp[j] = pathline[i];
        j++;
    }
    tmp[j] = '\0';
    free(pathline);
    new_env = str_to_array(tmp, ":");
    free(tmp);
    return new_env;
}

char **check_path(linked_mysh_t *ptr)
{
    char *pathline = NULL;
    char **valid_env = NULL;

    while (ptr != NULL) {
        if (my_strncmp("PATH=", ptr->env, 5) == SUCCESS) {
            pathline = my_strdup(ptr->env);
            break;
        }
        ptr = ptr->next;
    }
    valid_env = remove_path(pathline);
    return valid_env;
}

void error_signal(int error)
{
    int len = my_strlen(strsignal(WTERMSIG(error)));

    if (my_strcmp(strsignal(WTERMSIG(error)), "Floating point exception") == 0)
        write(2, "Floating exception", 18);
    else
        write(2, strsignal(WTERMSIG(error)), len);
    if (__WCOREDUMP(error))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
}

void free_array(char **command)
{
    for (size_t i = 0; command[i] != NULL; i++)
        free(command[i]);
    free(command);
}

int free_all(linked_mysh_t *ptr, char *line, char **input)
{
    linked_mysh_t *tmp = ptr;

    free_array(input);
    if (line != NULL)
        free(line);
    while (ptr != NULL) {
        free(ptr->env);
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    free(ptr);
    my_putstr("exit\n");
    return SUCCESS;
}
