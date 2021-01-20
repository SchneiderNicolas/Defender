/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Vertex.h>
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "csfml_object.h"
#include "stats.h"
#include "list_allys.h"
#include "csfml_text.h"

typedef enum bool_s
{
    FALSE,
    TRUE
} bool_t;

typedef enum
{
    MENU = 0,
    BATTLE,
    SETTINGS,
    SELECT_LEVEL,
    PAUSE,
    LOSE,
    WIN,
    RULES
} scene_e;

typedef enum
{
    KNIGHT_SHOP = 0,
    ARCHER_SHOP,
    KING_SHOP,
    WIZARD_SHOP,
    MINER_SHOP,
    BG_GAME,
    BG_SETTINGS,
    VOLUME,
    B_ON_OFF_MUSIC,
    B_ON_OFF_SOUND,
    B_PLUS,
    B_MINUS,
    B_BACK,
    B_RES1,
    B_RES2,
    B_RES3,
    PARA_1_CP,
    PARA_1,
    PARA_2_CP,
    PARA_2,
    PARA_3_CP,
    PARA_3,
    PARA_4_CP,
    PARA_4,
    PARA_5_CP,
    PARA_5,
    KNIGHT_IDLE,
    KNIGHT_ATTACK,
    KNIGHT_DEATH,
    ARCHER_IDLE,
    ARCHER_ATTACK,
    ARCHER_DEATH,
    KING_IDLE,
    KING_ATTACK,
    KING_DEATH,
    WIZARD_IDLE,
    WIZARD_ATTACK,
    WIZARD_DEATH,
    MINER_IDLE,
    MINER_ATTACK,
    MINER_WALK,
    BG_MENU,
    B_PLAY,
    B_SETTINGS,
    B_RULES,
    B_QUIT,
    BG_LEVEL,
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    BG_PAUSE,
    B_MENU,
    B_QUITP,
    B_RESUME,
    B_SETTINGSP,
    WALK_A,
    ATTACK_A,
    DEATH_A,
    WALK_B,
    ATTACK_B,
    DEATH_B,
    WALK_C,
    ATTACK_C,
    DEATH_C,
    WALK_D,
    ATTACK_D,
    DEATH_D,
    WALK_E,
    ATTACK_E,
    DEATH_E,
    WALK_F,
    ATTACK_F,
    DEATH_F,
    WALK_G,
    ATTACK_G,
    DEATH_G,
    WALK_H,
    ATTACK_H,
    DEATH_H,
    WALK_I,
    ATTACK_I,
    DEATH_I,
    WALK_J,
    ATTACK_J,
    DEATH_J,
    WALK_L,
    ATTACK_L,
    DEATH_L,
    WALK_M,
    ATTACK_M,
    DEATH_M,
    WALK_N,
    ATTACK_N,
    DEATH_N,
    WALK_O,
    ATTACK_O,
    DEATH_O,
    WALK_P,
    ATTACK_P,
    DEATH_P,
    WALK_Q,
    ATTACK_Q,
    DEATH_Q,
    WALK_R,
    ATTACK_R,
    DEATH_R,
    WALK_S,
    ATTACK_S,
    DEATH_S,
    WALK_T,
    ATTACK_T,
    DEATH_T,
    WALK_U,
    ATTACK_U,
    DEATH_U,
    WALK_V,
    ATTACK_V,
    DEATH_V,
    WALK_W,
    ATTACK_W,
    DEATH_W,
    WALK_X,
    ATTACK_X,
    DEATH_X,
    A,
    Z,
    E,
    R,
    T,
    B_CONTINUE,
    BG_WIN,
    BG_LOSE,
    HP,
    ARROW,
    SPELL,
    BG_RULES,
    BG_RULES1,
    BG_RULES2,
    BG_RULES3,
    B_NEXT
} sprite_e;

typedef enum
{
    MONEY = 0,
    BUY_KNIGHT,
    BUY_ARCHER,
    BUY_KING,
    BUY_WIZARD,
    BUY_MINER,
    UP_KNIGHT,
    UP_ARCHER,
    UP_KING,
    UP_WIZARD,
    UP_MINER,
    MONEY_END,
} text_e;

typedef enum
{
    BG_MUSIC = 0,
    E_DEATH,
    A_DEATH
} music_e;

typedef struct mouse_s
{
    sfVector2i position;
    bool_t click;
    sfMouseButtonEvent pos_click;
    int line;
    int columne;
} mouse_t;

typedef struct info_s
{
    scene_e scene;
    mouse_t *mouse;
    double updateRest;
    sfView *view;
    bool_t sound;
    float volume;
    int res;
    stats_t **stats_allys;
    stats_enemy_t **stats_enemy;
    stats_miner_t *stats_miner;
    int unlocked_level;
    int last_scene;
    int **board;
    int money;
    int hp;
    int rules;
} info_t;

typedef struct gui_s
{
    sfRenderWindow *window;
    sfClock *updateTimer;
    sfClock *dispTimer;
    sfMusic **music;
    info_t *info;
    csfml_object_t **object;
    csfml_object_t **board;
    list_allys_t *list_allys;
    list_miner_t *list_miner;
    list_enemy_t *list_enemy;
    csfml_text_t **text;
    char ***level;
    list_shot_t *list_shot;
    int lvl;
} gui_t;

#endif //GAME_H
