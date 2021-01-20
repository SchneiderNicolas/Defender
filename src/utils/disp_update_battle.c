/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** diaplay menu.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void display_shop(gui_t *game)
{
    displayer(game->window, game->object[BG_GAME]);
    for (int i = A; i <= T; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = KNIGHT_SHOP; i <= MINER_SHOP; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = KNIGHT_SHOP; i <= MINER_SHOP; i++) {
        game->object[i]->position.x += 867;
    }
    for (int i = KNIGHT_SHOP; i <= MINER_SHOP; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = 0; i < 30; i++) {
        displayer(game->window, game->board[i]);
    }
}

void set_texture_shop_board(gui_t *game)
{
    for (int i = KNIGHT_SHOP; i <= MINER_SHOP; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite, game->object[i]->rect);
    }
    for (int i = 0; i < 30; i++) {
        update_board_info(game, game->board[i], i);
        sfSprite_setTextureRect(game->board[i]->sprite, game->board[i]->rect);
    }
}