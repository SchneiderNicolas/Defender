/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** write in file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../include/prototype.h"

int write_in_save(char *text)
{
    int fp;
    fp = open("save/unlocked_level.txt", O_WRONLY);
    if (fp < 0)
        return (0);
    write(fp, text, my_strlen(text));
    close (fp);
    return (1);
}