/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** move miner
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void move_miner_right(list_miner_t *tmp)
{
    if (tmp->status == WALKING && tmp->direction == RIGHT) {
        if (tmp->object[WALKING]->position.x <= 1150) {
            tmp->object[WALKING]->position.x += 10;
        } else {
            tmp->object[MINE]->position.x = 1150;
            tmp->status = MINE;
        }
    }
}

void move_miner_mine(list_miner_t *tmp)
{
    if (tmp->status == MINE) {
        tmp->nb_mine += 1;
    }
    if (tmp->nb_mine == 30) {
        tmp->status = WALKING;
        tmp->direction = LEFT;
        tmp->object[WALKING]->position.x = 1300;
        tmp->object[WALKING]->scale.x = -1;
        tmp->nb_mine = 0;
    }
}

void move_miner_left(list_miner_t *tmp, gui_t *game)
{
    if (tmp->status == WALKING && tmp->direction == LEFT) {
        if (tmp->object[WALKING]->position.x >= 300) {
            tmp->object[WALKING]->position.x -= 10;
        } else {
            tmp->object[WALKING]->position.x = 180;
            tmp->object[WALKING]->scale.x = 1;
            tmp->direction = RIGHT;
            game->info->money += tmp->stats->gain;
        }
    }
}

void move_miner(gui_t *game)
{
    static int timer_walk = 0;
    static int timer_mine = 0;
    timer_walk++;
    if (timer_walk == 35) {
        for (list_miner_t *tmp = game->list_miner; tmp != NULL;
        tmp = tmp->next) {
            move_rect(tmp->object[tmp->status]);
            sfSprite_setTextureRect(tmp->object[tmp->status]->sprite,
                                    tmp->object[tmp->status]->rect);
            move_miner_right(tmp);
            move_miner_mine(tmp);
            move_miner_left(tmp, game);
        }
        timer_walk = 0;
    }
}