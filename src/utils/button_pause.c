/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button pause
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_resume(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_RESUME]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->scene = BATTLE;
    }
}

void b_menu(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_MENU]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        free_list_enemy(game->list_enemy);
        game->info->scene = MENU;
    }
}

void b_settingsp(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_SETTINGSP]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = PAUSE;
        game->info->scene = SETTINGS;
    }
}

void b_quitp(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_QUITP]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        sfRenderWindow_close(game->window);
    }
}