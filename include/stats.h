/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/

#ifndef STATS_H
#define STATS_H

typedef enum
{
    KNIGHT = 0,
    ARCHER,
    KING,
    WIZARD,
    MINER
} class_e;

typedef enum
{
    MOB_A,
    MOB_B,
    MOB_C,
    MOB_D,
    MOB_E,
    MOB_F,
    MOB_G,
    MOB_H,
    MOB_I,
    MOB_J,
    MOB_L,
    MOB_M,
    MOB_N,
    MOB_O,
    MOB_P,
    MOB_Q,
    MOB_R,
    MOB_S,
    MOB_T,
    MOB_U,
    MOB_V,
    MOB_W,
    MOB_X
} enemy_e;

typedef struct stats_s
{
    int hp;
    int dmg;
    int lvl;
    int price;
    int hp_up;
    int dmg_up;
    int price_up;
    int upgrade;
    int upgrade_up;
} stats_t;

typedef struct stats_enemy_s
{
    int hp;
    int dmg;
} stats_enemy_t;

typedef struct stats_miner_s
{
    int gain;
    int lvl;
    int price;
    int gain_up;
    int price_up;
    int upgrade;
    int upgrade_up;
} stats_miner_t;
#endif //STATS_H