/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void free_node(list_allys_t *node)
{
    sfSprite_destroy(node->object[IDLE]->sprite);
    sfSprite_destroy(node->object[ATTACK]->sprite);
    sfSprite_destroy(node->object[DEATH]->sprite);
    sfTexture_destroy(node->object[IDLE]->texture);
    sfTexture_destroy(node->object[ATTACK]->texture);
    sfTexture_destroy(node->object[DEATH]->texture);
    free(node->object[IDLE]);
    free(node->object[DEATH]);
    free(node->object[ATTACK]);
    free(node->stats);
}

void free_node_enemy(list_enemy_t *node)
{
    sfSprite_destroy(node->object[WALK]->sprite);
    sfSprite_destroy(node->object[ATCK]->sprite);
    sfSprite_destroy(node->object[DIE]->sprite);
    sfTexture_destroy(node->object[WALK]->texture);
    sfTexture_destroy(node->object[ATCK]->texture);
    sfTexture_destroy(node->object[DIE]->texture);
    free(node->object[WALK]);
    free(node->object[DIE]);
    free(node->object[ATCK]);
    free(node->stats);
}

void free_list_enemy(list_enemy_t *head)
{
    for (; head != NULL; head = head->next) {
        free_node_enemy(head);
    }
}