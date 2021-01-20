/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

char *get_line(FILE *fd)
{
    char *line = NULL;
    size_t len = 0;
    __ssize_t read;

    if (fd == NULL)
        return (NULL);
    read = getline(&line, &len, fd);
    return (line);
}
