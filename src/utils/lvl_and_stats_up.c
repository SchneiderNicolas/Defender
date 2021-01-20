/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gale.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void up_stats(stats_t *stats)
{
    stats->dmg += stats->dmg_up;
    stats->price += stats->price_up;
    stats->hp += stats->hp_up;
    stats->upgrade += stats->upgrade_up;
    stats->lvl += 1;
}

void up_stats_miner(stats_miner_t *stats)
{
    stats->gain += stats->gain_up;
    stats->price += stats->price_up;
    stats->upgrade += stats->upgrade_up;
    stats->lvl += 1;
}

void level_up(sfMouseButtonEvent event, csfml_object_t **object, gui_t *game)
{
    sfFloatRect hit_box;

    for (int i = KNIGHT_SHOP; i <= WIZARD_SHOP; i++) {
        hit_box = sfSprite_getGlobalBounds(object[i]->sprite);
        if (sfFloatRect_contains(&hit_box, event.x, event.y)
            && object[i]->rect.top < 200 && game->info->money >=
            game->info->stats_allys[i]->upgrade) {
            object[i]->rect.top += object[i]->rect.height;
            game->info->money -= game->info->stats_allys[i]->upgrade;
            up_stats(game->info->stats_allys[i]);
            return;
        }
    }
}

void level_up_miner(sfMouseButtonEvent event, csfml_object_t **object,
gui_t *game)
{
    sfFloatRect hit_box;

    hit_box = sfSprite_getGlobalBounds(object[MINER_SHOP]->sprite);
    if (sfFloatRect_contains(&hit_box, event.x, event.y)
        && object[MINER_SHOP]->rect.top < 200 && game->info->money >=
        game->info->stats_miner->upgrade) {
        object[MINER_SHOP]->rect.top += object[MINER_SHOP]->rect.height;
        game->info->money -= game->info->stats_miner->upgrade;
        up_stats_miner(game->info->stats_miner);
        return;
    }
}
