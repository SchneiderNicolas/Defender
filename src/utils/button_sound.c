/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button sound
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_on_off_sound(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, e.x, e.y) && object->rect.left == 0) {
        object->rect.left = object->rect.width;
        game->info->sound = FALSE;
    } else if (sfFloatRect_contains(&rec, e.x, e.y) &&
    object->rect.left != 0 ) {
        object->rect.left = 0;
        game->info->sound = TRUE;
    }
}