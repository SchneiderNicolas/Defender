/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int clone_mob_u(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_U;
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
    give_stats_enemy(game->info->stats_enemy[MOB_U], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_v(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_V;
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
    give_stats_enemy(game->info->stats_enemy[MOB_V], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_w(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_W;
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
    give_stats_enemy(game->info->stats_enemy[MOB_W], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_x(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_X;
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
    give_stats_enemy(game->info->stats_enemy[MOB_X], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}