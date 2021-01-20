/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/
#ifndef LIB_CSFML_OBJECT_H
#define LIB_CSFML_OBJECT_H

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct {
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} csfml_object_t;

#endif //CSFML_OBJECT_H
