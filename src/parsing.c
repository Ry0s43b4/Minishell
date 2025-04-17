/*
** EPITECH PROJECT, 2025
** 2minishell
** File description:
** parsing.c
*/

#include "my.h"

static int line_to_check(char *command)
{
    int nbr_of_pipes = 0;

    if (command == NULL)
        return ERROR;
    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == '|')
            nbr_of_pipes++;
    if (nbr_of_pipes == 0)
        return SUCCESS;
    return nbr_of_pipes;
}

int check_separators(linked_mysh_t *ptr, char *command, char **pathline)
{
    char **check = NULL;
    char **command1 = NULL;
    char **command2 = NULL;

    if (line_to_check(command) == SUCCESS)
        return ERROR;
    check = my_str_to_word_array(command, '|');
    if (check[1] == NULL) {
        write(2, "Invalid null command.\n", 22);
        free_array(check);
        return SUCCESS;
    }
    command1 = clean_input(check[0]);
    command2 = clean_input(check[1]);
    free_array(check);
    my_pipe(command1, command2, ptr, pathline);
    free_array(command1);
    return SUCCESS;
}
