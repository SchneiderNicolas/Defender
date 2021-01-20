/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button quit
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_quit(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_QUIT]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        sfRenderWindow_close(game->window);
    }
}