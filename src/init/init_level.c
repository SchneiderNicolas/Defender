/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

static const char *LEVEL[NB_LEVEL] = {
        "./level/level_1.txt",
        "./level/level_2.txt",
        "./level/level_3.txt",
        "./level/level_4.txt"
};

int get_map(gui_t *game)
{
    int i = 0;
    int j = 0;
    int y = 0;
    FILE *fd = NULL;

    game->level = malloc(sizeof(char **) * (NB_LEVEL + 1));
    for (; i < NB_LEVEL; i++) {
        fd = fopen(LEVEL[i], "r");
        game->level[i] = malloc(sizeof(char *) * 7);
        for (y = 0; y < 5; y++) {
            game->level[i][y] = get_line(fd);
        }
        game->level[i][y] = NULL;
    }
    game->level[i] = NULL;
    return (1);
}

void pt_funct_enemy(char c, gui_t *game, int x, int y)
{
    char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L',
                'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'};
    int (*funct[])(gui_t *, int, int) = {clone_mob_a, clone_mob_b, clone_mob_c,
                clone_mob_d, clone_mob_e, clone_mob_f, clone_mob_g, clone_mob_h,
                clone_mob_i, clone_mob_j, clone_mob_l, clone_mob_m,
                clone_mob_n, clone_mob_o, clone_mob_p, clone_mob_q, clone_mob_r,
                clone_mob_s, clone_mob_t, clone_mob_u, clone_mob_v, clone_mob_w,
                clone_mob_x};

    for (int j = 0; j < 23; j++) {
        if (game->level[game->lvl][y][x] == letter[j]) {
                funct[j](game, x, y);
                return;
        }
    }
}

int init_level(gui_t *game)
{
    get_map(game);
    for (int y = 0; game->level[game->lvl][y] != NULL; y++) {
        for (int x = 0; game->level[game->lvl][y][x] != '\0'; x++) {
            pt_funct_enemy(game->level[game->lvl][y][x], game, x, y);
        }
    }
    list_enemy_t *tmp = game->list_enemy;
    return (1);
}