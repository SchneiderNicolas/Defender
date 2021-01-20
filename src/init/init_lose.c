/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init lose
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_lose(gui_t *game)
{
    game->object[BG_LOSE]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[B_CONTINUE]->position = (sfVector2f){.x = 650, .y = 560};
    game->object[B_CONTINUE]->rect = (sfIntRect){0, 0, 300, 68};
    game->text[MONEY_END]->character_size = 45;
    game->text[MONEY_END]->position = (sfVector2f){.x = 850, .y = 438};
    sfText_setPosition(game->text[MONEY_END]->text,
                            game->text[MONEY_END]->position);
    sfText_setCharacterSize(game->text[MONEY_END]->text,
                                game->text[MONEY_END]->character_size);
    sfText_setColor(game->text[MONEY_END]->text, game->text[MONEY_END]->color);
    sfText_setString(game->text[MONEY_END]->text, "0");
    sfText_setFont(game->text[MONEY_END]->text, game->text[MONEY_END]->font);
    return (1);
}