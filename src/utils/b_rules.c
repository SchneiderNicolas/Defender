/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button rules
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_rules(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_RULES]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->scene = RULES;
    }
}