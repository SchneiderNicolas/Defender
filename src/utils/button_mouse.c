/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button mouse
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_mouse(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);
    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->rect.left = object->rect.width;
    } else {
        object->rect.left = 0;
    }
}