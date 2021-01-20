/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void update_rect_shop_allys(gui_t *game)
{
    static int timer = 0;

    ++timer;
    if (timer == 35) {
        for (int i = KNIGHT_SHOP; i <= KING_SHOP; i++)
            move_rect(game->object[i]);
        for (list_allys_t *tmp = game->list_allys; tmp != NULL;
            tmp = tmp->next) {
            if (tmp->class == KING || tmp->class == KNIGHT ||
                (tmp->class == ARCHER && tmp->status != ATTACK)) {
                move_rect(tmp->object[tmp->status]);
                sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                                    tmp->object[tmp->status]->rect);
            }
        }
    timer = 0;
    }
}

void update_rect_attack_distance(gui_t *game)
{
    static int timer3 = 0;

    ++timer3;
    if (timer3 == 75) {
        for (list_allys_t *tmp = game->list_allys; tmp != NULL;
            tmp = tmp->next) {
            if ((tmp->class == WIZARD && tmp->status == ATTACK) ||
                (tmp->class == ARCHER && tmp->status == ATTACK)) {
                move_rect(tmp->object[tmp->status]);
                sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                                    tmp->object[tmp->status]->rect);
            }
        }
    timer3 = 0;
    }
}

void update_rect_miner_enemy(gui_t *game)
{
    for (list_miner_t *tmp = game->list_miner; tmp != NULL; tmp = tmp->next) {
        move_rect(tmp->object[tmp->status]);
        sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                            tmp->object[tmp->status]->rect);
    }
    for (list_enemy_t *tmp = game->list_enemy; tmp != NULL; tmp = tmp->next) {
        move_rect(tmp->object[tmp->status]);
        sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                            tmp->object[tmp->status]->rect);
    }
}

void update_rect_shop_enemy(gui_t *game)
{
    static int timer2 = 0;
    static int timer = 0;
    ++timer2;
    ++timer;
    if (timer2 == 55){
        for (int i = WIZARD_SHOP; i <= MINER_SHOP; i++)
            move_rect(game->object[i]);
        timer2 = 0;
    }
    if (timer == 40) {
        for (list_allys_t *tmp = game->list_allys; tmp != NULL; tmp = tmp->next)
            if (tmp->class == WIZARD && tmp->status != ATTACK) {
                move_rect(tmp->object[tmp->status]);
                sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                                    tmp->object[tmp->status]->rect);
            }
        update_rect_miner_enemy(game);
        check_attack(game);
        timer = 0;
    }
}