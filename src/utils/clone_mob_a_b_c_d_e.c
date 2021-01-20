/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int clone_mob_a(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_A;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                        (158 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_A], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_b(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_B;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                        (158 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_B], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_c(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_C;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = WALK; i <= DIE; i++, j++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[j]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[j]->texture);
        node->status = WALK;
        node->object[i]->rect = (sfIntRect){0, 0, 120, 120};
        node->object[i]->position = (sfVector2f){(1700 + (x * 120)),
                                            (158 + (y * 118))};
        node->object[i]->scale = (sfVector2f){-1, 1};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->dead = FALSE;
    node->stats = malloc(sizeof(stats_enemy_t));
    give_stats_enemy(game->info->stats_enemy[MOB_C], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_d(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_D;
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
    give_stats_enemy(game->info->stats_enemy[MOB_D], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}

int clone_mob_e(gui_t *game, int x, int y)
{
    list_enemy_t *node = malloc(sizeof(list_enemy_t));
    int j = WALK_E;
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
    give_stats_enemy(game->info->stats_enemy[MOB_E], node);
    game->list_enemy = add_node_enemy(game->list_enemy, node);
    return (1);
}