/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** clone_allys.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void give_stats_allys(stats_t *stats, list_allys_t *ally)
{

    ally->stats->hp = stats->hp;
    ally->stats->dmg = stats->dmg;
    ally->stats->lvl = stats->lvl;
    ally->stats->price = stats->price;
    ally->stats->hp_up = stats->hp_up;
    ally->stats->dmg_up = stats->dmg_up;
    ally->stats->price_up = stats->price_up;
    ally->stats->upgrade = stats->upgrade;
    ally->stats->upgrade_up = stats->upgrade_up;
}

void give_stats_miner(stats_miner_t *stats, list_miner_t *miner)
{
    miner->stats->gain = stats->gain;
    miner->stats->lvl = stats->lvl;
    miner->stats->price = stats->price;
    miner->stats->gain_up = stats->gain_up;
    miner->stats->price_up = stats->price_up;
}

void give_stats_enemy(stats_enemy_t *stats, list_enemy_t *enemy)
{
    enemy->stats->hp = stats->hp;
    enemy->stats->dmg = stats->dmg;
}