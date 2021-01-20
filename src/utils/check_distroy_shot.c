/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void free_node_shot(list_shot_t *node)
{
    sfSprite_destroy(node->object->sprite);
    sfTexture_destroy(node->object->texture);
    free(node->object);
}

int distroy_node_shot(list_enemy_t *mob, list_shot_t *tmp, sfFloatRect enemy)
{
    sfFloatRect shot = sfSprite_getGlobalBounds(tmp->next->object->sprite);

    if (sfFloatRect_intersects(&enemy, &shot, NULL) && mob->status != DIE) {
        mob->stats->hp -= tmp->next->dmg;
        free_node_shot(tmp->next);
        tmp->next = tmp->next->next;
        return (1);
    }
    if (tmp->next->object->position.x >= 1500) {
        free_node_shot(tmp->next);
        tmp->next = tmp->next->next;
        return (1);
    }
    return (0);
}

void check_distroy_shot(gui_t *game, sfFloatRect enemy, list_enemy_t *mob)
{
    list_shot_t *tmp = game->list_shot; sfFloatRect shot;
    if (tmp == NULL)
        return;
    shot = sfSprite_getGlobalBounds(game->list_shot->object->sprite);
    if (sfFloatRect_intersects(&enemy, &shot, NULL) && mob->status != DIE) {
            mob->stats->hp -= tmp->dmg;
            free_node_shot(tmp);
            game->list_shot = tmp->next;
            return;
    }
    if (game->list_shot->object->position.x >= 1500) {
        free_node_shot(tmp);
        game->list_shot = tmp->next;
        return;
    }
    while (tmp->next != NULL) {
        if (distroy_node_shot(mob, tmp, enemy) == 1)
            return;
        tmp = tmp->next;
    }
}