/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void displayer(sfRenderWindow *window, csfml_object_t *object)
{
    sfSprite_setPosition(object->sprite, object->position);
    sfSprite_setScale(object->sprite, object->scale);
    sfRenderWindow_drawSprite(window , object->sprite, NULL);
}