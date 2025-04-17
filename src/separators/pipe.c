/*
** EPITECH PROJECT, 2025
** 2minishell
** File description:
** pipe.c
*/

#include "my.h"

static void child_exec(int *pipe_fd, char **cmd1, linked_mysh_t *ptr,
    char **pathline)
{
    close(pipe_fd[0]);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);
    check(ptr, cmd1, pathline);
    exit(EXIT_SUCCESS);
}

int my_pipe(char **cmd1, char **cmd2, linked_mysh_t *ptr, char **pathline)
{
    pid_t child = 0;
    int fdd[2] = {0};
    int copy_stdin = dup(STDIN_FILENO);

    if (pipe(fdd) < 0)
        return ERROR;
    child = fork();
    if (child == 0) {
        child_exec(fdd, cmd1, ptr, pathline);
        free_array(pathline);
    } else {
        close(fdd[1]);
        dup2(fdd[0], STDIN_FILENO);
        close(fdd[0]);
        check(ptr, cmd2, pathline);
        wait(0);
        dup2(copy_stdin, STDIN_FILENO);
    }
    return SUCCESS;
}
