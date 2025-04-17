/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** commands.c
*/

#include "my.h"

static int execution(char **args, char *command, linked_mysh_t *ptr)
{
    pid_t pid = fork();
    int status = 0;
    char **static_env = linked_list_into_array(ptr);

    if (pid == 0)
        execve(command, args, static_env);
    if (pid != 0) {
        wait(&status);
        if (WIFSIGNALED(status))
            error_signal(status);
    }
    free_array(static_env);
    return SUCCESS;
}

static int bin_command(char **command, linked_mysh_t *ptr)
{
    struct stat file;

    if (access(command[0], F_OK) != SUCCESS)
        return EXIT_FAILURE;
    stat(command[0], &file);
    if (access(command[0], X_OK) != SUCCESS ||
    S_ISDIR(file.st_mode) != SUCCESS) {
        write(2, command[0], my_strlen(command[0]));
        write(2, ": Permission denied.\n", 20);
        free_array(command);
        return SUCCESS;
    }
    execution(command, command[0], ptr);
    free_array(command);
    return SUCCESS;
}

static int is_builtin(linked_mysh_t *ptr, char **command)
{
    for (int i = 0; i < BUILTINS_NBR; i++) {
        if (my_strcmp(command[0], BUILTINS[i].builtin) == SUCCESS) {
            BUILTINS[i].function_to_use(ptr, command);
            return SUCCESS;
        }
    }
    return ERROR;
}

int exec(char **command, char **pathline, linked_mysh_t *ptr)
{
    char *str = NULL;
    char *tmp = NULL;

    for (size_t i = 0; pathline[i]; i++) {
        tmp = my_strcat("/", command[0]);
        str = my_strcat(pathline[i], tmp);
        if (access(str, F_OK) == SUCCESS) {
            execution(command, str, ptr);
            free(str);
            free(tmp);
            free_array(command);
            return SUCCESS;
        }
        free(str);
        free(tmp);
    }
    return ERROR;
}

int check(linked_mysh_t *ptr, char **command, char **pathline)
{
    if (is_builtin(ptr, command) == SUCCESS)
        return SUCCESS;
    if (bin_command(command, ptr) == SUCCESS)
        return SUCCESS;
    if (exec(command, pathline, ptr) == SUCCESS)
        return SUCCESS;
    write(2, command[0], my_strlen(command[0]));
    write(2, ": Command not found.\n", 21);
    free_array(command);
    return EXIT_FAILURE;
}
