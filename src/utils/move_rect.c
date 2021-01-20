/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void move_rect(csfml_object_t *object)
{
    unsigned int max_value = sfTexture_getSize(object->texture).x;

    if (object->rect.left + object->rect.width >= max_value) {
        object->rect.left = 0;
        return;
    }
    object->rect.left += object->rect.width;
}