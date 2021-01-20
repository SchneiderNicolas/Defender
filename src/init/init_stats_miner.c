/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void fill_stats_miner(char **stats, stats_miner_t *stat_miner)
{
    stat_miner->gain = my_getnbr(stats[0]);
    stat_miner->lvl = my_getnbr(stats[1]);
    stat_miner->price = my_getnbr(stats[2]);
    stat_miner->gain_up = my_getnbr(stats[3]);
    stat_miner->price_up = my_getnbr(stats[4]);
    stat_miner->upgrade = my_getnbr(stats[5]);
    stat_miner->upgrade_up = my_getnbr(stats[6]);
}

int init_stats_miner(gui_t *game)
{
    FILE *fd = NULL;
    int i = 0;
    char **stats;

    fd = fopen("./stats/stats_miner.txt", "r");
    game->info->stats_miner = malloc(sizeof(stats_miner_t));
    if (!game->info->stats_miner)
        return (0);
    stats = my_str_to_word_array(get_line(fd), ' ');
    fill_stats_miner(stats, game->info->stats_miner);
    return (1);
}