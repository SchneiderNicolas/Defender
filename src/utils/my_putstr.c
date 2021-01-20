/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** my putsdtr
*/

#include "../../include/prototype.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}