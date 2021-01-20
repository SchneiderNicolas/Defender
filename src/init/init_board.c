/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init board
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int fill_board_struct(gui_t *game, int x, sfTexture *board_button, int i )
{
    int y = 0;

    for (; i < 30; i++) {
        game->board[i] = malloc(sizeof(csfml_object_t));
        game->board[i]->sprite = sfSprite_create();
        if (game->board[i] == NULL || game->board[i]->sprite == NULL)
            return (0);
        game->board[i]->texture = board_button;
        game->board[i]->scale = (sfVector2f){1, 1};
        game->board[i]->position = (sfVector2f){.x = 358 + x, .y = 162 + y};
        game->board[i]->rect = (sfIntRect){0, 0, 114, 114};
        if ((i + 1) % 6 == 0 && i > 0) {
            x = 0;
            y += 118;
        } else
            x += 118;
        sfSprite_setTexture(game->board[i]->sprite, game->board[i]->texture,
                            sfTrue);
    }
    game->board[i] = NULL;
}

int init_board(gui_t *game)
{
    int x = 0;
    int i = 0;
    sfTexture *board_button =
    sfTexture_createFromFile("./assets/ButtonBoard.png", NULL);
    game->board = malloc(sizeof(csfml_object_t *) * 31);

    if (game->board == NULL || board_button == NULL)
        return (0);
    if (fill_board_struct(game, x, board_button, i) == 0)
        return (0);
    return (1);
}