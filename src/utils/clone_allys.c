/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int clone_allys2(gui_t *game, int nb_miner)
{
    for (list_miner_t *tmp = game->list_miner; tmp != NULL; tmp = tmp->next,
        nb_miner += 1);
    if (sfKeyboard_isKeyPressed(sfKeyT) && check_price_miner(game) == 1 &&
        nb_miner < 10) {
        clone_miner(game);
        remove_money_miner(game);
    }
    return (1);
}

int clone_allys(gui_t *game)
{
    int nb_miner = 0;
    sfKeyCode com[] = {sfKeyA, sfKeyZ, sfKeyE, sfKeyR};
    void (*funct[])(gui_t *) = {clone_knight, clone_archer,
        clone_king, clone_wizard};
    int (*check_price[])(gui_t *) = {check_price_knight, check_price_archer,
        check_price_king, check_price_wizard};
    void (*remove_money[])(gui_t *) = {remove_money_knight,
        remove_money_archer, remove_money_king, remove_money_wizard};
    for (int i = 0; i < 4; i++) {
        if (sfKeyboard_isKeyPressed(com[i]) && check_price[i](game) == 1 &&
        check_pos_mouse(game)) {
            funct[i](game);
            remove_money[i](game);
            return (1);
        }
    }
    clone_allys2(game, nb_miner);
    return (1);
}