/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

void create_shot(gui_t *game, list_allys_t *ally)
{
    list_shot_t *node = malloc(sizeof(list_shot_t));

    node->dmg = ally->stats->dmg;
    node->object = malloc(sizeof(csfml_object_t));
    if (ally->class == WIZARD) {
        node->object->sprite = sfSprite_copy(game->object[SPELL]->sprite);
        node->object->texture = sfTexture_copy(game->object[SPELL]->texture);
        node->object->rect = (sfIntRect){0, 0, 50, 50};
    } else if (ally->class == ARCHER) {
        node->object->sprite = sfSprite_copy(game->object[ARROW]->sprite);
        node->object->texture = sfTexture_copy(game->object[ARROW]->texture);
        node->object->rect = (sfIntRect){0, 0, 60, 24};
    }
    node->object->position.x = (ally->object[ATTACK]->position.x + 50);
    node->object->position.y = (ally->object[ATTACK]->position.y + 40);
    sfSprite_setTextureRect(node->object->sprite, node->object->rect);
    node->object->scale = (sfVector2f){1, 1};
    node->next = NULL;
    game->list_shot = add_node_shot(game->list_shot, node);
}