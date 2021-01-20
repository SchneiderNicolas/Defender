/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** update_hp
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void update_hp(gui_t *game)
{
    game->object[HP]->rect.left = 272 * game->info->hp;
    sfSprite_setTextureRect(game->object[HP]->sprite, game->object[HP]->rect);
}