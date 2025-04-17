/*
** EPITECH PROJECT, 2024
** my_ str to word array
** File description:
** Cut a string into an array
*/

#include "my.h"

char **delete_empty_line(char **old_array)
{
    char **new_array = NULL;
    int count = 0;
    int j = 0;

    for (int i = 0; old_array[i] != NULL; i++) {
        if (my_strlen(old_array[i]) != 0)
            count++;
    }
    new_array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; old_array[i] != NULL; i++) {
        if (my_strlen(old_array[i]) != 0) {
            new_array[j] = my_strdup(old_array[i]);
            j++;
        }
    }
    new_array[count] = NULL;
    for (int i = 0; old_array[i] != NULL; i++)
        free(old_array[i]);
    free(old_array);
    return new_array;
}

char *my_str_to_word(char const *str, int x, char separator)
{
    int size = 0;
    char *dest = NULL;
    int y = 0;

    for (int i = x; str[i] != separator && str[i] != '\0'; i++)
        size++;
    dest = malloc(sizeof(char) * (size + 1));
    while (str[x] != separator && str[x] != '\0') {
        dest[y] = str[x];
        y++;
        x++;
    }
    dest[size] = '\0';
    return dest;
}

char **my_str_to_word_array(char const *str, char separator)
{
    int size = 1;
    char **array = NULL;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
            size++;
    }
    array = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        array[i] = my_str_to_word(str, index, separator);
        for (int j = index; str[j] != separator && str[j] != '\0'; j++)
            index++;
        index++;
    }
    array[size] = NULL;
    array = delete_empty_line(array);
    return array;
}
