/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** clone_allys.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void clone_miner_lvl(gui_t *game, list_miner_t *node, int i)
{
    if (game->info->stats_miner->lvl == 1)
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
    else if (game->info->stats_miner->lvl == 2)
        node->object[i]->rect = (sfIntRect){0, 130, 130, 130};
    else
        node->object[i]->rect = (sfIntRect){0, 260, 130, 130};
}