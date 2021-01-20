/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** scene rules
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_rules(gui_t *game)
{
    game->object[B_NEXT]->position = (sfVector2f){.x = 1478, .y = 740};
    game->object[B_NEXT]->rect = (sfIntRect){0, 0, 50, 72};
    return (1);
}