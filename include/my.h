/*
** EPITECH PROJECT, 2024
** My h
** File description:
** Header file for including functions without a C-H1 Coding-style
*/

#ifndef MY_H_
    #define MY_H_
    #include "macro.h"
    #include "include.h"
    #include "struct.h"

typedef void (*ptr_t) (va_list flag);
int mini_printf(const char *format, ...);
int check_flag(char const *format, va_list flag, int j);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str, char cond);
char *my_strdup(char const *str);
int check(linked_mysh_t *ptr, char **command, char **pathline);
int free_all(linked_mysh_t *ptr, char *line, char **input);
char **check_path(linked_mysh_t *ptr);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *str1, char const *str2, int n);
void free_array(char **command);
void error_signal(int error);
linked_mysh_t *add_node_to_list(linked_mysh_t *ptr, char *line);
int display_env(linked_mysh_t *ptr, char **command);
int my_setenv(linked_mysh_t *ptr, char **command);
int my_unsetenv(linked_mysh_t *ptr, char **command);
int loop(linked_mysh_t *ptr);
linked_mysh_t *remove_node_from_list(linked_mysh_t *ptr);
int my_cd(linked_mysh_t *ptr, char **command);
char **linked_list_into_array(linked_mysh_t *ptr);
int my_pipe(char **cmd1, char **cmd2, linked_mysh_t *ptr, char **pathline);
void redirections(void);
void semicolons(void);
int check_separators(linked_mysh_t *ptr, char *command, char **pathline);
int exec(char **command, char **pathline, linked_mysh_t *ptr);
char **clean_input(char *command);

static const ptr_to_func_t BUILTINS[BUILTINS_NBR] = {
    {"env", display_env},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"cd", my_cd}
};

#endif /* MY_H_ */
