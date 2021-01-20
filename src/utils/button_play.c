/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button play
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_play(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_PLAY]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->scene = SELECT_LEVEL;
    }
}