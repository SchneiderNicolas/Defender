/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** select level
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_level1(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[LEVEL1]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->lvl = 0;
        free_stats_allys(game);
        init_stats_miner(game);
        init_stats_ally(game);
        init_battle(game);
        init_level(game);
        game->info->scene = BATTLE;
    }
}

void b_level2(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[LEVEL2]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
            game->info->unlocked_level >= 2) {
        game->lvl = 1;
        free_stats_allys(game);
        init_stats_miner(game);
        init_stats_ally(game);
        init_battle(game);
        init_level(game);
        game->info->scene = BATTLE;
    }
}

void b_level3(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[LEVEL3]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
            game->info->unlocked_level >= 3) {
        game->lvl = 2;
        free_stats_allys(game);
        init_stats_miner(game);
        init_stats_ally(game);
        init_battle(game);
        init_level(game);
        game->info->scene = BATTLE;
    }
}

void b_level4(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[LEVEL4]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
            game->info->unlocked_level >= 4) {
        game->lvl = 3;
        free_stats_allys(game);
        init_stats_miner(game);
        init_stats_ally(game);
        init_battle(game);
        init_level(game);
        game->info->scene = BATTLE;
    }
}
