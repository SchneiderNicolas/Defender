/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** int to str
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int my_intlen(int nb)
{
    int count = 0;

    while (nb > 0) {
        nb /= 10;
        ++count;
    }
    return (count);
}

char *int_to_str(int nb)
{
    int malloc_size = my_intlen(nb);
    char *res = malloc(sizeof(char) * (malloc_size + 1));
    int nb2 = 0;
    int i = 0;
    int size = malloc_size - 1;
    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (res);
    }
    while (nb > 9) {
        nb2 = nb;
        nb2 %= 10;
        res[size] = nb2 + '0';
        nb /= 10;
        size--;
    }
    res[size] = nb + '0';
    res[malloc_size] = '\0';
    return (res);
}
