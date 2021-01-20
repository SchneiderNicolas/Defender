/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init_select_level
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_select_level(gui_t *game)
{
    game->object[BG_LEVEL]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[LEVEL1]->position = (sfVector2f){.x = 479, .y = 183};
    game->object[LEVEL1]->rect = (sfIntRect){0, 0, 115, 142};
    game->object[LEVEL2]->position = (sfVector2f){.x = 610, .y = 183};
    game->object[LEVEL2]->rect = (sfIntRect){0, 0, 116, 142};
    game->object[LEVEL3]->position = (sfVector2f){.x = 742, .y = 183};
    game->object[LEVEL3]->rect = (sfIntRect){0, 0, 116, 142};
    game->object[LEVEL4]->position = (sfVector2f){.x = 874, .y = 183};
    game->object[LEVEL4]->rect = (sfIntRect){0, 0, 116, 142};
    return (1);
}