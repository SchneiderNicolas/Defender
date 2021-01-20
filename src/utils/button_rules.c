/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button rules
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int button_back_rules(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->scale.x = 1.1;
        object->scale.y = 1.1;
    } else {
        object->scale.x = 1;
        object->scale.y = 1;
    }
    return (1);
}

int button_next_rules(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->scale.x = 1.1;
        object->scale.y = 1.1;
    } else {
        object->scale.x = 1;
        object->scale.y = 1;
    }
    return (1);
}

void b_next(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(object->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) && game->info->rules != 4) {
        game->info->rules += 1;
    }
}

void b_back(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(object->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) && game->info->rules != 1) {
        game->info->rules -= 1;
    } else if (sfFloatRect_contains(&rec, e.x, e.y) && game->info->rules == 1){
        game->info->scene = MENU;
    }
}
