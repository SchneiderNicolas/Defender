/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init.h for Defender
*/

#ifndef INIT_H
#define INIT_H

#include "macro.h"
#include "game.h"

int init_game(gui_t *game);
int init_images(gui_t *game);
int init_menu(gui_t *game);
int init_musics(gui_t *game);
int init_info(gui_t *game);
int init_battle(gui_t *game);
int init_settings(gui_t *game);
int init_select_level(gui_t *game);
int init_pause(gui_t *game);
int init_board(gui_t *game);
int init_level(gui_t *game);
int init_stats_enemy(gui_t *game);
int init_stats_ally(gui_t *game);
int init_stats_miner(gui_t *game);
int init_text(gui_t *game);
int init_lose(gui_t *game);
int init_win(gui_t *game);
int init_rules(gui_t *game);

struct tor_s {
    int (*tor)(gui_t *game);
} tor_t;

const struct tor_s INIT[NB_INIT] =
    {{&init_game},
    {&init_images},
    {&init_menu},
    {&init_musics},
    {&init_info},
    {&init_text},
    {&init_battle},
    {&init_settings},
    {&init_select_level},
    {&init_stats_enemy},
    {&init_stats_miner},
    {&init_stats_ally},
    {&init_pause},
    {&init_board},
    {&init_lose},
    {&init_win},
    {&init_rules}
};

#endif //INIT_H