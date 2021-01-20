/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** number of unlocked level
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../include/prototype.h"

int nb_unlocked_level(void)
{
    char *line = NULL;
    size_t len = 0;
    FILE *fd = NULL;
    __ssize_t read;

    fd = fopen("save/unlocked_level.txt", "r");
    if (fd == NULL)
        return (1);
    read = getline(&line, &len, fd);
    fclose(fd);
    return (my_getnbr(line));
}