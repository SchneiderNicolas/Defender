/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button back
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int button_back(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->scale.x = 1.1;
        object->scale.y = 1.1;
        if (game->info->mouse->click)
            game->info->scene = game->info->last_scene;
    } else {
        object->scale.x = 1;
        object->scale.y = 1;
    }
    return (1);
}