/*
** EPITECH PROJECT, 2018
** scene.h
** File description:
** scene.h for Defender
*/

#ifndef SCENE_H
#define SCENE_H

#include "macro.h"
#include "game.h"

int loop_menu(gui_t *game);
int loop_battle(gui_t *game);
int loop_settings(gui_t *game);
int loop_select_level(gui_t *game);
int loop_pause(gui_t *game);
int loop_lose(gui_t *game);
int loop_win(gui_t *game);
int loop_rules(gui_t *game);

struct loop_s
{
    int (*loop_scene)(gui_t *game);
} loop_t;

const struct loop_s SCENE[NB_SCENE] = {
        {&loop_menu},
        {&loop_battle},
        {&loop_settings},
        {&loop_select_level},
        {&loop_pause},
        {&loop_lose},
        {&loop_win},
        {&loop_rules}
};


#endif //SCENE_H