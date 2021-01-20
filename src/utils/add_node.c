/*
** EPITECH PROJECT, 2019
** open_window
** File description:
** my_hunter
*/

#include "../../include/game.h"
#include "../../include/macro.h"

list_allys_t *add_node(list_allys_t *head, list_allys_t *node)
{
    list_allys_t *tmp = NULL;

    if (head == NULL) {
        tmp = node;
        tmp->next = NULL;
        head = tmp;
        return (head);
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (head);
}

list_miner_t *add_node_miner(list_miner_t *head, list_miner_t *node)
{
    list_miner_t *tmp = NULL;

    if (head == NULL) {
        tmp = node;
        tmp->next = NULL;
        head = tmp;
        return (head);
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (head);
}

list_enemy_t *add_node_enemy(list_enemy_t *head, list_enemy_t *node)
{
    list_enemy_t *tmp = NULL;

    if (head == NULL) {
        tmp = node;
        tmp->next = NULL;
        head = tmp;
        return (head);
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (head);
}

list_shot_t *add_node_shot(list_shot_t *head, list_shot_t *node)
{
    list_shot_t *tmp = NULL;

    if (head == NULL) {
        tmp = node;
        tmp->next = NULL;
        head = tmp;
        return (head);
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (head);
}
