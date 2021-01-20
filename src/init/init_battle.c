/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void reset_board(gui_t *game)
{
    for (int i = 0; game->info->board[i] != NULL; i++) {
        for (int j = 0; j < 6; j++) {
            game->info->board[i][j] = 0;
        }
    }
}

int reset_pos(gui_t *game)
{
    game->object[KNIGHT_SHOP]->position = (sfVector2f){75, 35};
    game->object[ARCHER_SHOP]->position = (sfVector2f){197, 33};
    game->object[KING_SHOP]->position = (sfVector2f){314, 37};
    game->object[WIZARD_SHOP]->position = (sfVector2f){427, 40};
    game->object[MINER_SHOP]->position = (sfVector2f){550, 40};
    return (1);
}

void set_position_text(gui_t *game)
{
    int x1 = 107;
    float x2 = 975;

    game->text[MONEY]->position = (sfVector2f){775, 112};
    for (int i = BUY_KNIGHT; i <= BUY_MINER; i++) {
        game->text[i]->position = (sfVector2f){x1, 135};
        x1 += 120;
    }
    for (int i = UP_KNIGHT; i <= UP_MINER; i++) {
        game->text[i]->position = (sfVector2f){x2, 135};
        x2 += 119.5;
    }
}

int init_text_battle(gui_t *game)
{
    set_position_text(game);
    game->text[MONEY]->character_size = 30;
    for (int i = MONEY; i <= UP_MINER; i++) {
        sfText_setFont(game->text[i]->text, game->text[i]->font);
        sfText_setString(game->text[i]->text, "0");
        sfText_setCharacterSize(game->text[i]->text,
                                game->text[i]->character_size);
        sfText_setColor(game->text[i]->text, game->text[i]->color);
        sfText_setPosition(game->text[i]->text, game->text[i]->position);
    }
    return (1);
}

int init_battle(gui_t *game)
{
    int x = 104;
    game->list_allys = NULL;
    game->list_shot = NULL;
    game->list_enemy = NULL;
    game->list_miner = NULL;
    for (int y = KNIGHT_SHOP; y <= MINER_SHOP; y++)
        game->object[y]->rect = (sfIntRect){0, 0, 100, 100};
    for (int i = A; i <= T; i++) {
        game->object[i]->position = (sfVector2f){.x = x, .y = 0};
        x += 120;
    }
    game->object[HP]->rect = (sfIntRect){0, 0, 272, 57};
    game->object[HP]->position = (sfVector2f){.x = 665, .y = 53};
    game->info->money = 500;
    game->info->hp = 0;
    reset_board(game);
    if (!init_text_battle(game)) {
        return (0);
    }
    return (1);
}