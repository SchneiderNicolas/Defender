/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init pause
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_pause(gui_t *game)
{
    game->object[BG_PAUSE]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[B_MENU]->position = (sfVector2f){.x = 650, .y = 372};
    game->object[B_MENU]->rect = (sfIntRect){0, 0, 300, 68};
    game->object[B_QUITP]->position = (sfVector2f){.x = 650, .y = 576};
    game->object[B_QUITP]->rect = (sfIntRect){0, 0, 300, 68};
    game->object[B_RESUME]->position = (sfVector2f){.x = 650, .y = 270};
    game->object[B_RESUME]->rect = (sfIntRect){0, 0, 300, 68};
    game->object[B_SETTINGSP]->position = (sfVector2f){.x = 650, .y = 474};
    game->object[B_SETTINGSP]->rect = (sfIntRect){0, 0, 300, 68};
    return (1);
}