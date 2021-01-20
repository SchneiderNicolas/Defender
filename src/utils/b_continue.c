/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button continue
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_continue(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_CONTINUE]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        free_list_enemy(game->list_enemy);
        game->info->last_scene = MENU;
        game->info->scene = SELECT_LEVEL;
    }
}

void b_continue_win(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_CONTINUE]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->unlocked_level += 1;
        write_in_save(int_to_str(game->info->unlocked_level));
        game->info->last_scene = MENU;
        game->info->scene = SELECT_LEVEL;
    }
}