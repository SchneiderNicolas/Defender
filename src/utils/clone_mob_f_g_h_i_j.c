/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int clone_mob_f(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_F;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                        (150 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_F], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_g(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_G;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (150 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_G], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_h(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_H;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (150 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_H], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_i(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_I;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (150 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_I], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_j(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_J;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 130, 130};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (150 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_J], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}