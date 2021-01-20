/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init settings
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_settings2(gui_t *game)
{
    game->object[B_RES1]->position = (sfVector2f){.x = 700, .y = 382};
    game->object[B_RES1]->rect = (sfIntRect){0, 0, 60, 57};
    game->object[B_RES2]->position = (sfVector2f){.x = 825, .y = 382};
    game->object[B_RES2]->rect = (sfIntRect){0, 0, 60, 57};
    game->object[B_RES3]->position = (sfVector2f){.x = 950, .y = 382};
    game->object[B_RES3]->rect = (sfIntRect){60, 0, 60, 57};
    game->object[B_BACK]->position = (sfVector2f){.x = 50, .y = 740};
    game->object[B_BACK]->rect = (sfIntRect){0, 0, 50, 72};
    return (1);
}

int init_settings(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5_CP; i += 2)
        game->object[i]->position = (sfVector2f){.x = 1600, .y = 0};
    game->object[B_ON_OFF_MUSIC]->position = (sfVector2f){.x = 650, .y = 505};
    game->object[B_ON_OFF_MUSIC]->rect = (sfIntRect){0, 0, 150, 75};
    game->object[B_ON_OFF_SOUND]->position = (sfVector2f){.x = 950, .y = 505};
    game->object[B_ON_OFF_SOUND]->rect = (sfIntRect){0, 0, 150, 75};
    game->object[B_PLUS]->position = (sfVector2f){.x = 1005.7, .y = 270};
    game->object[B_PLUS]->rect = (sfIntRect){0, 0, 70, 69};
    game->object[B_MINUS]->position = (sfVector2f){.x = 700, .y = 270};
    game->object[B_MINUS]->rect = (sfIntRect){0, 0, 70, 69};
    game->object[VOLUME]->position = (sfVector2f){.x = 770, .y = 270};
    game->object[VOLUME]->rect = (sfIntRect){1414, 0, 236, 69};
    init_settings2(game);
    return (1);
}