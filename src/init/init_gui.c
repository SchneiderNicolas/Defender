/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>

int fill_info_struct(gui_t *game)
{
    game->info->stats_allys = malloc(sizeof(stats_t) * (NB_ALLYS + 1));
    game->info->stats_miner = malloc(sizeof(stats_miner_t));
    game->info->mouse = malloc(sizeof(mouse_t));
    if (!game->info->mouse || !game->info->stats_allys ||
        !game->info->stats_miner)
        return (0);
    game->info->mouse->click = FALSE;
    game->info->mouse->position = (sfVector2i){0, 0};
    game->info->sound = TRUE;
    game->info->volume = 7;
    game->info->res = 8;
    game->info->unlocked_level = nb_unlocked_level();
    game->info->last_scene = MENU;
    game->info->money = 1000;
    game->info->hp = 0;
    game->info->rules = 1;
    return (1);
}

int init_info_board(gui_t *game)
{
    int i = 0;

    game->info->board = malloc(sizeof(int *) * 6);
    if (!game->info->board)
        return (0);
    for (; i < 5; i++) {
        game->info->board[i] = malloc(sizeof(int) * 6);
        if (!game->info->board[i])
            return (0);
        for (int j = 0; j < 6; j++) {
            game->info->board[i][j] = 0;
        }
    }
    game->info->board[i] = NULL;
}

int init_info(gui_t *game)
{
    game->info = malloc(sizeof(info_t));
    if (!game->info)
        return (0);
    game->info->scene = MENU;
    game->info->updateRest = 0;
    game->info->view = sfView_create();
    sfView_setCenter(game->info->view, (sfVector2f){WIN_WIDTH / 2,
                                        WIN_HEIGHT / 2});
    sfView_setSize(game->info->view, (sfVector2f){WIN_WIDTH, WIN_HEIGHT});
    if (fill_info_struct(game) == 0)
        return (0);
    if (!(init_info_board(game)))
        return (0);
    return (1);
}

int init_game(gui_t *game)
{
    game->window = NULL;
    game->dispTimer = sfClock_create();
    game->updateTimer = sfClock_create();
    game->list_allys = NULL;
    game->list_enemy = NULL;
    game->list_miner = NULL;
    return (1);
}

int init_musics(gui_t *game)
{
    game->music = malloc(sizeof(sfMusic *) * (NB_MUSIC + 1));
    if (!game->music || !init_music(game))
        return (0);
    return (1);
}