/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** clone_allys.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void set_pos_ally(gui_t *game, list_allys_t *node, int i, int type)
{
    if (game->info->stats_allys[type]->lvl == 1)
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
    else if (game->info->stats_allys[type]->lvl == 2)
        node->object[i]->rect = (sfIntRect){0, 130, 130, 130};
    else
        node->object[i]->rect = (sfIntRect){0, 260, 130, 130};
    node->object[i]->scale = game->object[i]->scale;
    node->object[i]->position = (sfVector2f){340 + 120 *
            game->info->mouse->columne, 150 + 118 * game->info->mouse->line};
}