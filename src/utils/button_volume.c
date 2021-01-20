/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button volume
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_plus_mouse(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);
    rec = sfSprite_getGlobalBounds(object->sprite);
    if (game->info->volume == 7) {
        object->rect.left = 2 * object->rect.width;
    } else if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->rect.left = object->rect.width;
    } else {
        object->rect.left = 0;
    }
}

void b_minus_mouse(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);
    rec = sfSprite_getGlobalBounds(object->sprite);
    if (game->info->volume == 1) {
        object->rect.left = 2 * object->rect.width;
    } else if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->rect.left = object->rect.width;
    } else {
        object->rect.left = 0;
    }
}

void b_plus_music(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(object->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) && game->info->volume < 7) {
        game->object[VOLUME]->rect.left += game->object[VOLUME]->rect.width;
        game->info->volume += 1;
        sfMusic_setVolume(game->music[BG_MUSIC], 100 / 6 *
                            game->info->volume - 16);
    }
}

void b_minus_music(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(object->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) && game->info->volume > 1) {
        game->object[VOLUME]->rect.left -= game->object[VOLUME]->rect.width;
        sfMusic_setVolume(game->music[BG_MUSIC], 100 / 6 *
                            game->info->volume - 32);
        game->info->volume -= 1;
    }
}