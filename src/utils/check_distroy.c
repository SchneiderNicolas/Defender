/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int condition_to_distroy(list_allys_t *tmp, unsigned int max_value,
                        gui_t *game)
{
    if (tmp->next->status == DEATH && (tmp->next->object[DEATH]->rect.left +
        tmp->next->object[DEATH]->rect.width) >= max_value) {
        game->info->board[tmp->next->line][tmp->next->columne] = 0;
        free_node(tmp->next);
        tmp->next = tmp->next->next;
        return (1);
    }
    return (0);
}

int condition_distroy_enemy(list_enemy_t *tmp, unsigned int max_value,
                                gui_t *game, unsigned int max_value_atck)
{
    if (tmp->next->status == DIE && (tmp->next->object[DIE]->rect.left +
        tmp->next->object[DIE]->rect.width) >= max_value) {
        free_node_enemy(tmp->next);
        tmp->next = tmp->next->next;
        return (1);
    } else if (tmp->next->status == ATCK && (tmp->next->object[ATCK]->rect.left
        + tmp->next->object[ATCK]->rect.width) >= max_value_atck &&
        tmp->next->object[ATCK]->position.x <= 430) {
        game->info->hp += 1;
        free_node_enemy(tmp->next);
        tmp->next = tmp->next->next;
        return (1);
    }
    return (0);
}

int distroy_first_node_enemy(list_enemy_t *tmp, unsigned int max_value,
                            gui_t *game, unsigned int max_value_atck)
{
    if (tmp->status == DIE && (tmp->object[DIE]->rect.left +
        tmp->object[DIE]->rect.width) >= max_value) {
        free_node_enemy(tmp);
        game->list_enemy = tmp->next;
        return (1);
    } else if (tmp->status == ATCK && (tmp->object[ATCK]->rect.left +
            tmp->object[ATCK]->rect.width) >= max_value_atck &&
            tmp->object[ATCK]->position.x <= 430) {
        free_node_enemy(tmp);
        game->list_enemy = tmp->next;
        game->info->hp += 1;
        return (1);
    }
    return (0);
}

void check_distroy_allys(gui_t *game)
{
    list_allys_t *tmp = game->list_allys;
    unsigned int max_value;

    if (tmp == NULL)
        return;
    max_value = sfTexture_getSize(tmp->object[DEATH]->texture).x;
    if (tmp->status == DEATH && (tmp->object[DEATH]->rect.left +
            tmp->object[DEATH]->rect.width) >= max_value) {
            game->info->board[tmp->line][tmp->columne] = 0;
            free_node(tmp);
            game->list_allys = tmp->next;
            return;
    }
    while (tmp->next != NULL) {
        max_value = sfTexture_getSize(tmp->next->object[DEATH]->texture).x;
        if (condition_to_distroy(tmp, max_value, game) == 1)
            return;
        tmp = tmp->next;
    }
}

void check_distroy_enemys(gui_t *game)
{
    list_enemy_t *tmp = game->list_enemy;
    unsigned int max_value;
    unsigned int max_value_atck;

    if (tmp == NULL)
        return;
    max_value = sfTexture_getSize(tmp->object[DIE]->texture).x;
    max_value_atck = sfTexture_getSize(tmp->object[ATCK]->texture).x;
    if (distroy_first_node_enemy(tmp, max_value, game, max_value_atck) == 1)
        return;
    while (tmp->next != NULL) {
        max_value_atck = sfTexture_getSize(tmp->object[ATCK]->texture).x;
        max_value = sfTexture_getSize(tmp->next->object[DEATH]->texture).x;
        if (condition_distroy_enemy(tmp, max_value, game, max_value_atck) == 1)
            return;
        tmp = tmp->next;
    }
}