/*
** EPITECH PROJECT, 2025
** my str to word array (new version)
** File description:
** Cut a string into an array
*/

#include "my.h"

static bool is_sep(char c, char *seps)
{
    for (size_t i = 0; seps[i]; ++i)
        if (seps[i] == c)
            return true;
    return false;
}

static char **delete_empty_line(char **old_array)
{
    char **new_array = NULL;
    size_t count = 0;
    size_t j = 0;

    for (size_t i = 0; old_array[i] != NULL; ++i)
        if (my_strlen(old_array[i]) != 0)
            ++count;
    new_array = malloc(sizeof(char *) * (count + 1));
    if (new_array == NULL)
        return NULL;
    for (size_t i = 0; old_array[i] != NULL; ++i)
        if (my_strlen(old_array[i]) != 0) {
            new_array[j] = my_strdup(old_array[i]);
            ++j;
        }
    new_array[count] = NULL;
    for (size_t i = 0; old_array[i] != NULL; ++i)
        free(old_array[i]);
    free(old_array);
    return new_array;
}

static char *cut_to_word(char const *str, size_t x, char *seps)
{
    size_t size = 0;
    char *dest = NULL;
    size_t y = 0;

    for (size_t i = x; str[i] != '\0'; ++i)
        if (!is_sep(str[i], seps))
            ++size;
    dest = malloc(sizeof(char) * (size + 1));
    if (dest == NULL)
        return NULL;
    while (!is_sep(str[x], seps) && str[x] != '\0') {
        dest[y] = str[x];
        ++y;
        ++x;
    }
    dest[size] = '\0';
    return dest;
}

char **str_to_array(char const *str, char *seps)
{
    size_t size = 1;
    char **array = NULL;
    size_t index = 0;

    for (size_t i = 0; str[i] != '\0'; ++i)
        if (is_sep(str[i], seps))
            ++size;
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL)
        return NULL;
    for (size_t i = 0; i < size; ++i) {
        array[i] = cut_to_word(str, index, seps);
        for (size_t j = index; !is_sep(str[j], seps) && str[j] != '\0'; ++j)
            ++index;
        ++index;
    }
    array[size] = NULL;
    array = delete_empty_line(array);
    return array;
}
