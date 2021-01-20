/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** update board info
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void update_board_info(gui_t *game, csfml_object_t *object, int pos)
{
    int y = pos % 6;
    int x = pos / 6;
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);
    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        if (game->info->board[x][y] == 2) {
            object->rect.left = object->rect.width;
        } else {
            object->rect.left = 2 * object->rect.width;
            game->info->board[x][y] = 1;
        }
    } else {
        object->rect.left = 0;
        if (game->info->board[x][y] != 2)
            game->info->board[x][y] = 0;
    }
}