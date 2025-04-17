/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** cd.c
*/

#include "my.h"

static char *find_in_env(linked_mysh_t *ptr, char *name)
{
    char *line = NULL;
    char *value = NULL;
    int size = 0;
    int index = 0;

    for (linked_mysh_t *tmp = ptr; tmp; tmp = tmp->next) {
        if (my_strncmp(name, tmp->env, my_strlen(name)) == SUCCESS) {
            line = my_strdup(tmp->env);
            break;
        }
    }
    size = my_strlen(line) - my_strlen(name);
    value = malloc(sizeof(char) * (size + 1));
    for (int i = my_strlen(name); line[i] != '\0'; i++) {
        value[index] = line[i];
        index++;
    }
    value[size] = '\0';
    free(line);
    return value;
}

static void setenv_for_pwd(linked_mysh_t *ptr, char *old_pwd, char *new_pwd)
{
    char **command = NULL;
    char **command1 = NULL;

    command = malloc(sizeof(char *) * (3 + 1));
    command[0] = my_strdup("setenv");
    command[1] = my_strdup("PWD");
    command[2] = my_strdup(new_pwd);
    command[3] = NULL;
    my_setenv(ptr, command);
    command1 = malloc(sizeof(char *) * (3 + 1));
    command1[0] = my_strdup("setenv");
    command1[1] = my_strdup("OLDPWD");
    command1[2] = my_strdup(old_pwd);
    command1[3] = NULL;
    my_setenv(ptr, command1);
}

static int check_dir(char *dir)
{
    DIR *directory;

    directory = opendir(dir);
    if (directory == NULL) {
        mini_printf("%s: No such file or directory.\n", dir);
        return ERROR;
    }
    closedir(directory);
    return SUCCESS;
}

static void my_cd1(linked_mysh_t *ptr, char *old_pwd)
{
    char *home = NULL;

    home = find_in_env(ptr, "HOME=");
    chdir(home);
    setenv_for_pwd(ptr, old_pwd, home);
    free(home);
}

static void my_cd2(linked_mysh_t *ptr, char *actual_pwd)
{
    char *new = NULL;

    new = find_in_env(ptr, "OLDPWD=");
    chdir(new);
    setenv_for_pwd(ptr, actual_pwd, new);
    free(new);
}

static int check_cd(linked_mysh_t *ptr, char **command, char *old_pwd)
{
    if (command[1] == NULL) {
        my_cd1(ptr, old_pwd);
        return SUCCESS;
    }
    if (command[1] != NULL && my_strcmp(command[1], "~") == SUCCESS) {
        my_cd1(ptr, old_pwd);
        return SUCCESS;
    }
    if (command[1] != NULL && my_strcmp(command[1], "-") == SUCCESS) {
        my_cd2(ptr, old_pwd);
        return SUCCESS;
    }
    return ERROR;
}

int my_cd(linked_mysh_t *ptr, char **command)
{
    char *old_pwd = getcwd(NULL, 0);
    char *new_pwd = NULL;

    if (check_cd(ptr, command, old_pwd) == SUCCESS) {
        free(old_pwd);
        free_array(command);
        return SUCCESS;
    }
    if (command[1] != NULL && check_dir(command[1]) == ERROR) {
        free_array(command);
        free(old_pwd);
        return SUCCESS;
    }
    chdir(command[1]);
    new_pwd = getcwd(NULL, 0);
    setenv_for_pwd(ptr, old_pwd, new_pwd);
    free_array(command);
    free(old_pwd);
    free(new_pwd);
    return SUCCESS;
}
