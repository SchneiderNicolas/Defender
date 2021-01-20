/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int check_pos_mouse(gui_t *game)
{
    int line = -1;
    int colone = -1;
    for (int y = 0; game->info->board[y] != NULL; y++) {
        for (int x = 0; x < 6; x++) {
            if (game->info->board[y][x] == 1) {
                game->info->mouse->line = y;
                game->info->mouse->columne = x;
                game->info->board[y][x] = 2;
                return (1);
            }
        }
    }
    return (0);
}
