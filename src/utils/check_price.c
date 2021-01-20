/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** check price
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int check_price_knight(gui_t *game)
{
    if (game->info->money >= game->info->stats_allys[KNIGHT]->price) {
        return 1;
    }
    return (0);
}

int check_price_archer(gui_t *game)
{
    if (game->info->money >= game->info->stats_allys[ARCHER]->price) {
        return 1;
    }
    return (0);
}

int check_price_king(gui_t *game)
{
    if (game->info->money >= game->info->stats_allys[KING]->price) {
        return 1;
    }
    return (0);
}

int check_price_wizard(gui_t *game)
{
    if (game->info->money >= game->info->stats_allys[WIZARD]->price) {
        return 1;
    }
    return (0);
}

int check_price_miner(gui_t *game)
{
    if (game->info->money >= game->info->stats_miner->price) {
        return 1;
    }
    return (0);
}