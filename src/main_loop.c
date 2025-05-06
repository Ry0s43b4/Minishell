/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** main_loop.c
*/

#include "my.h"

char **linked_list_into_array(linked_mysh_t *ptr)
{
    linked_mysh_t *tmp = ptr;
    char **array = NULL;
    int i = 0;
    int lines = 0;

    for (; tmp != NULL; tmp = tmp->next)
        lines++;
    array = malloc(sizeof(char *) * (lines + 1));
    if (array == NULL)
        return NULL;
    for (tmp = ptr; tmp != NULL; tmp = tmp->next) {
        array[i] = my_strdup(tmp->env);
        i++;
    }
    array[i] = NULL;
    return array;
}

char **clean_input(char *command)
{
    char *clean_command = NULL;
    char **final_input = NULL;
    int len = 0;

    if (my_strlen(command) == 1)
        return NULL;
    for (; command[len] != '\n' && command[len] != '\0'; len++);
    clean_command = malloc(sizeof(char) * (len + 1));
    for (size_t i = 0; command[i] != '\0'; i++) {
        if (command[i] == '\t')
            clean_command[i] = ' ';
        else
            clean_command[i] = command[i];
    }
    clean_command[len] = '\0';
    final_input = str_to_array(clean_command, " ");
    free(clean_command);
    return final_input;
}

int loop(linked_mysh_t *ptr)
{
    char *line = NULL;
    size_t len = 0;
    char **pathline = NULL;
    int reading = 0;
    char **input = NULL;

    pathline = check_path(ptr);
    while (1) {
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("(✖╭╮✖) ლ(´◉❥◉´ლ)→ ");
        reading = getline(&line, &len, stdin);
        if ((reading == -1) || (my_strncmp(line, "exit", 4) == SUCCESS))
            return free_all(ptr, line, pathline);
        if (check_separators(ptr, line, pathline) == SUCCESS)
            continue;
        input = clean_input(line);
        if (input != NULL)
            check(ptr, input, pathline);
    }
    return SUCCESS;
}
