/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_music
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/macro.h"
#include "../../include/game.h"

const char *MUSIC[NB_MUSIC] = {
    "sounds/bg_music.ogg",
    "sounds/aargh2.ogg",
    "sounds/aargh6.ogg"
};

int init_music(gui_t *game)
{
    int i = 0;

    for (; i < NB_MUSIC; i++) {
        game->music[i] = sfMusic_createFromFile(MUSIC[i]);
        if (!game->music[i])
            return (0);
    }
    game->music[i] = NULL;
    return (1);
}
