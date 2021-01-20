/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** parallax
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void move_background(csfml_object_t *object, float speed, float restart)
{
    if (object->position.x <= -WIN_WIDTH) {
        object->position.x = restart;
    } else {
        object->position.x -= speed;
    }
}

void move_parallax(gui_t *game)
{
    move_background(game->object[PARA_1_CP], 0.01, WIN_WIDTH);
    move_background(game->object[PARA_1], 0.01, WIN_WIDTH);
    move_background(game->object[PARA_2_CP], 0.05, WIN_WIDTH);
    move_background(game->object[PARA_2], 0.05, WIN_WIDTH);
    move_background(game->object[PARA_3_CP], 0.07, WIN_WIDTH);
    move_background(game->object[PARA_3], 0.07, WIN_WIDTH);
    move_background(game->object[PARA_4_CP], 0.2, WIN_WIDTH);
    move_background(game->object[PARA_4], 0.2, WIN_WIDTH);
    move_background(game->object[PARA_5_CP], 0.5, WIN_WIDTH);
    move_background(game->object[PARA_5], 0.5, WIN_WIDTH);
}