/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** remove money
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void remove_money_knight(gui_t *game)
{
    game->info->money -= game->info->stats_allys[KNIGHT]->price;
}

void remove_money_archer(gui_t *game)
{
    game->info->money -= game->info->stats_allys[ARCHER]->price;
}

void remove_money_king(gui_t *game)
{
    game->info->money -= game->info->stats_allys[KING]->price;
}

void remove_money_wizard(gui_t *game)
{
    game->info->money -= game->info->stats_allys[WIZARD]->price;
}

void remove_money_miner(gui_t *game)
{
    game->info->money -= game->info->stats_miner->price;
}