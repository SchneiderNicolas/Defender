/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void fill_stats_enemy(char **stats, stats_enemy_t *stat_enemy)
{
    stat_enemy->hp = my_getnbr(stats[0]);
    stat_enemy->dmg = my_getnbr(stats[1]);
}

int init_stats_enemy(gui_t *game)
{
    FILE *fd = NULL;
    int i = 0;
    char **stats;

    fd = fopen("./stats/stats_enemy.txt", "r");
    game->info->stats_enemy = malloc(sizeof(stats_enemy_t *) * (NB_ENEMY + 1));
    if (!game->info->stats_enemy)
        return (0);
    for (; i < NB_ENEMY; i++) {
        game->info->stats_enemy[i] = malloc(sizeof(stats_enemy_t));
        if (!game->info->stats_enemy[i])
            return (0);
        stats = my_str_to_word_array(get_line(fd), ' ');
        fill_stats_enemy(stats, game->info->stats_enemy[i]);
    }
    game->info->stats_enemy[i] = NULL;
    return (1);
}