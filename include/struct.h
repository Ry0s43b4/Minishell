/*
** EPITECH PROJECT, 2024
** B-PSU-200-PAR-2-1-minishell1-nicky.truong
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct linked_mysh_s {
    char *env;
    struct linked_mysh_s *next;
} linked_mysh_t;

typedef struct btree {
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

typedef struct ptr_to_func_s {
    char *builtin;
    int (*function_to_use) (linked_mysh_t *, char **);
} ptr_to_func_t;

#endif /* STRUCT_H_ */
