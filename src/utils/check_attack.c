/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void check_attack(gui_t *game)
{
    sfFloatRect enemy;

    for (list_enemy_t *tmp_e = game->list_enemy; tmp_e != NULL;
        tmp_e = tmp_e->next) {
        for (int i = WALK; i <= DIE && tmp_e->status == WALK; i++)
            tmp_e->object[i]->position.x -= 3;
        enemy = sfSprite_getGlobalBounds(tmp_e->object[tmp_e->status]->sprite);
        enemy.height -= 30;
        enemy.width -= 20;
        for (list_allys_t *tmp_a = game->list_allys; tmp_a != NULL;
            tmp_a = tmp_a->next) {
            which_statement(tmp_a, tmp_e, enemy, game);
        }
        if (tmp_e->object[tmp_e->status]->position.x <= 430)
            tmp_e->status = ATCK;
        check_distroy_shot(game, enemy, tmp_e);
    }
}
