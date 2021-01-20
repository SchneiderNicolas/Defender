/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button settings
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_settings(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_SETTINGS]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->scene = SETTINGS;
    }
}