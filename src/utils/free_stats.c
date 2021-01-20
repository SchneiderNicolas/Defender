/*
** EPITECH PROJECT, 2019
** open_window
** File description:
** my_hunter
*/

#include "../../include/game.h"
#include "../../include/macro.h"

void free_stats_allys(gui_t *game)
{
    int i = 0;

    for (; game->info->stats_allys[i] != NULL; i++) {
        free(game->info->stats_allys[i]);
    }
    free(game->info->stats_allys[i]);
    free(game->info->stats_allys);
}