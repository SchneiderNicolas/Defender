/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int clone_mob_l(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_L;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (148 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_L], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_m(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_M;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (148 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_M], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_n(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_N;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (148 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_N], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_o(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_O;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (148 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_O], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}