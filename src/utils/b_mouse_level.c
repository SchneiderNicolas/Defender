/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** select level
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_mouse_level(gui_t *game, csfml_object_t **object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);

    for (int i = LEVEL1; i < LEVEL1 + game->info->unlocked_level; i++) {
        rec = sfSprite_getGlobalBounds(object[i]->sprite);
        if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
            object[i]->rect.left = object[i]->rect.width;
        } else {
            object[i]->rect.left = 0;
        }
    }
    for (int i = LEVEL1 + game->info->unlocked_level; i <= LEVEL4; i++) {
        object[i]->rect.left = object[i]->rect.width * 2;
    }
}
