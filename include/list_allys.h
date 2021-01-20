/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** game.h for Defender
*/

#ifndef LIST_ALLYS_H
#define LIST_ALLYS_H

#include "game.h"
#include "stats.h"

typedef enum
{
    IDLE = 0,
    ATTACK,
    DEATH,
} status_e;

typedef enum
{
    MINE = 1,
    WALKING,
} status_miner_e;

typedef enum
{
    WALK = 0,
    ATCK,
    DIE,
} status_enemy_e;

typedef enum
{
    RIGHT = 0,
    LEFT = 1,
} direction_e;

typedef struct list_allys_s
{
    class_e class;
    status_e status;
    csfml_object_t **object;
    stats_t *stats;
    int line;
    int columne;
    struct list_allys_s *next;
    int dead;
} list_allys_t;

typedef struct list_miner_s
{
    csfml_object_t **object;
    status_miner_e status;
    stats_miner_t *stats;
    struct list_miner_s *next;
    direction_e direction;
    int nb_mine;
} list_miner_t;

typedef struct list_enemy_s
{
    stats_enemy_t *stats;
    status_enemy_e status;
    csfml_object_t **object;
    struct list_enemy_s *next;
    int dead;
} list_enemy_t;

typedef struct list_shot_s
{
    csfml_object_t *object;
    int dmg;
    struct list_shot_s *next;
} list_shot_t;

#endif //LIST_ALLYS_H