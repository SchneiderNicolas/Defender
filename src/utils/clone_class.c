/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** clone_allys.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void clone_knight(gui_t *game)
{
    list_allys_t *node = malloc(sizeof(list_allys_t));
    int y = KNIGHT_IDLE;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = IDLE; i <= DEATH; i++, y++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[y]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[y]->texture);
        node->status = IDLE;
        node->line = game->info->mouse->line;
        node->columne = game->info->mouse->columne;
        node->dead = FALSE;
        set_pos_ally(game, node, i, KNIGHT);
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->stats = malloc(sizeof(stats_t));
    give_stats_allys(game->info->stats_allys[KNIGHT], node);
    node->class = KNIGHT;
    game->list_allys = add_node(game->list_allys, node);
}

void clone_archer(gui_t *game)
{
    list_allys_t *node = malloc(sizeof(list_allys_t));

    int y = ARCHER_IDLE;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = IDLE; i <= DEATH; i++, y++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[y]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[y]->texture);
        node->status = IDLE;
        node->line = game->info->mouse->line;
        node->columne = game->info->mouse->columne;
        node->dead = FALSE;
        set_pos_ally(game, node, i, ARCHER);
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->stats = malloc(sizeof(stats_t));
    give_stats_allys(game->info->stats_allys[ARCHER], node);
    node->class = ARCHER;
    game->list_allys = add_node(game->list_allys, node);
}

void clone_king(gui_t *game)
{
    list_allys_t *node = malloc(sizeof(list_allys_t));
    int i = IDLE;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int y = KING_IDLE; i <= DEATH; i++, y++) {
        node->object[i] = malloc(sizeof(csfml_object_t));

        node->object[i]->sprite = sfSprite_copy(game->object[y]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[y]->texture);
        node->status = IDLE;
        node->line = game->info->mouse->line;
        node->columne = game->info->mouse->columne;
        node->dead = FALSE;
        set_pos_ally(game, node, i, KING);
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->stats = malloc(sizeof(stats_t));
    give_stats_allys(game->info->stats_allys[KING], node);
    node->class = KING;
    game->list_allys = add_node(game->list_allys, node);
}

void clone_wizard(gui_t *game)
{
    list_allys_t *node = malloc(sizeof(list_allys_t));

    int y = WIZARD_IDLE;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = IDLE; i <= DEATH; i++, y++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[y]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[y]->texture);
        node->status = IDLE;
        node->line = game->info->mouse->line;
        node->columne = game->info->mouse->columne;
        node->dead = FALSE;
        set_pos_ally(game, node, i, WIZARD);
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->next = NULL;
    }
    node->stats = malloc(sizeof(stats_t));
    give_stats_allys(game->info->stats_allys[WIZARD], node);
    node->class = WIZARD;
    game->list_allys = add_node(game->list_allys, node);
}

void clone_miner(gui_t *game)
{
    list_miner_t *node = malloc(sizeof(list_miner_t));
    int y = MINER_IDLE;
    node->object = malloc(sizeof(csfml_object_t *) * 4);
    for (int i = IDLE; i <= DEATH; i++, y++) {
        node->object[i] = malloc(sizeof(csfml_object_t));
        node->object[i]->sprite = sfSprite_copy(game->object[y]->sprite);
        node->object[i]->texture = sfTexture_copy(game->object[y]->texture);
        clone_miner_lvl(game, node, i);
        node->object[i]->scale = game->object[i]->scale;
        node->object[i]->position = (sfVector2f){200, 765};
        sfSprite_setTextureRect(node->object[i]->sprite, node->object[i]->rect);
        node->status = WALKING;
        node->direction = RIGHT;
        node->nb_mine = 0;
        node->next = NULL;
    }
    node->stats = malloc(sizeof(stats_miner_t));
    give_stats_miner(game->info->stats_miner, node);
    game->list_miner = add_node_miner(game->list_miner, node);
}