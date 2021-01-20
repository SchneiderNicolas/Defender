/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button resolution
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void button_x2(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, e.x, e.y) && object->rect.left == 0) {
        object->rect.left = object->rect.width;
        game->object[B_RES2]->rect.left = 0;
        game->object[B_RES3]->rect.left = 0;
        game->info->res = 2;
    } else if (sfFloatRect_contains(&rec, e.x, e.y) &&
    object->rect.left != 0 && game->info->res != 2) {
        object->rect.left = 0;
    }
}

void button_x4(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, e.x, e.y) && object->rect.left == 0) {
        object->rect.left = object->rect.width;
        game->object[B_RES1]->rect.left = 0;
        game->object[B_RES3]->rect.left = 0;
        game->info->res = 4;
    } else if (sfFloatRect_contains(&rec, e.x, e.y) &&
    object->rect.left != 0 && game->info->res != 4) {
        object->rect.left = 0;
    }
}

void button_x8(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, e.x, e.y) && object->rect.left == 0) {
        object->rect.left = object->rect.width;
        game->object[B_RES1]->rect.left = 0;
        game->object[B_RES2]->rect.left = 0;
        game->info->res = 8;
    } else if (sfFloatRect_contains(&rec, e.x, e.y) &&
    object->rect.left != 0 && game->info->res != 8) {
        object->rect.left = 0;
    }
}