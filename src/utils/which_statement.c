/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void statement_if_dead(list_allys_t *tmp_a, list_enemy_t *tmp_e, gui_t *game)
{
    if (tmp_a->stats->hp <= 0) {
        tmp_a->status = DEATH;
        tmp_e->status = WALK;
        if (tmp_a->dead == FALSE && game->info->sound == TRUE) {
            sfMusic_stop(game->music[A_DEATH]);
            sfMusic_play(game->music[A_DEATH]);
            tmp_a->dead = TRUE;
        }
        return;
    } else if  (tmp_e->stats->hp <= 0) {
        tmp_a->status = IDLE;
        tmp_e->status = DIE;
        if (tmp_e->dead == FALSE && game->info->sound == TRUE) {
            sfMusic_stop(game->music[E_DEATH]);
            sfMusic_play(game->music[E_DEATH]);
            tmp_e->dead = TRUE;
        }
        return;
    }
}

void statement_if_wizard_archer2(list_allys_t *tmp_a, list_enemy_t *tmp_e,
                                gui_t *game)
{
    if (tmp_a->status == ATTACK && (tmp_a->object[ATTACK]->rect.left +
        tmp_a->object[ATTACK]->rect.width) >=
        sfTexture_getSize(tmp_a->object[ATTACK]->texture).x) {
        create_shot(game, tmp_a);
        tmp_a->object[ATTACK]->rect.left = 0;
    }
}

void statement_if_wizard_archer(list_allys_t *tmp_a, list_enemy_t *tmp_e,
                                gui_t *game)
{
    if (tmp_e->status == DIE)
        tmp_a->status = IDLE;
    else if (tmp_e->object[tmp_e->status]->position.x <= 1500 &&
        tmp_e->object[tmp_e->status]->position.y <=
        (tmp_a->object[tmp_a->status]->position.y + 15) &&
        tmp_e->object[tmp_e->status]->position.y >=
        (tmp_a->object[tmp_a->status]->position.y - 5) && tmp_a->status != DIE)
        tmp_a->status = ATTACK;
    statement_if_wizard_archer2(tmp_a, tmp_e, game);
}

void decrease_hp_and_statement_attack(list_allys_t *tmp_a, list_enemy_t *tmp_e)
{
    if (tmp_a->status != DEATH) {
        if (tmp_a->class == KING || tmp_a->class == KNIGHT) {
            tmp_a->status = ATTACK;
            tmp_e->stats->hp -= (tmp_a->stats->dmg / 10);
        }
        tmp_e->status = ATCK;
        tmp_a->stats->hp -= (tmp_e->stats->dmg / 10);
    }
}

void which_statement(list_allys_t *tmp_a, list_enemy_t *tmp_e, sfFloatRect e,
                    gui_t *game)
{
    sfFloatRect a;
    statement_if_dead(tmp_a, tmp_e, game);
    if (tmp_a != NULL) {
        a = sfSprite_getGlobalBounds(tmp_a->object[tmp_a->status]->sprite);
        a.height -= 30;
        a.width -= 20;
    }
    if (tmp_a->class == WIZARD || tmp_a->class == ARCHER) {
        statement_if_wizard_archer(tmp_a, tmp_e, game);
    }
    if (tmp_a != NULL && sfFloatRect_intersects(&e, &a, NULL) ==
        sfTrue && tmp_a->status != DEATH && tmp_e->status != DIE) {
            decrease_hp_and_statement_attack(tmp_a, tmp_e);
    }
}
