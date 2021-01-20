/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void fill_stats_ally(char **stats, stats_t *stat_ally)
{
    stat_ally->hp = my_getnbr(stats[0]);
    stat_ally->dmg = my_getnbr(stats[1]);
    stat_ally->lvl = my_getnbr(stats[2]);
    stat_ally->price = my_getnbr(stats[3]);
    stat_ally->hp_up = my_getnbr(stats[4]);
    stat_ally->dmg_up = my_getnbr(stats[5]);
    stat_ally->price_up = my_getnbr(stats[6]);
    stat_ally->upgrade = my_getnbr(stats[7]);
    stat_ally->upgrade_up = my_getnbr(stats[8]);
}

int init_stats_ally(gui_t *game)
{
    FILE *fd = NULL;
    int i = 0;
    char **stats;

    fd = fopen("./stats/stats_ally.txt", "r");
    game->info->stats_allys = malloc(sizeof(stats_t *) * (NB_ALLYS + 1));
    if (!game->info->stats_allys)
        return (0);
    for (; i < NB_ALLYS; i++) {
        game->info->stats_allys[i] = malloc(sizeof(stats_t));
        if (!game->info->stats_allys[i])
            return (0);
        stats = my_str_to_word_array(get_line(fd), ' ');
        fill_stats_ally(stats, game->info->stats_allys[i]);
    }
    game->info->stats_allys[i] = NULL;
    return (1);
}