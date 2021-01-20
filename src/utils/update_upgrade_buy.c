/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** update upgrade and buy
*/


#include "../../include/game.h"
#include "../../include/prototype.h"

void update_buy(gui_t *game)
{
    for (int i = BUY_KNIGHT; i <= BUY_WIZARD; i++) {
        if (game->info->stats_allys[i - 1]->price > game->info->money) {
            sfText_setColor(game->text[i]->text, sfRed);
            sfText_setString(game->text[i]->text,
                    int_to_str(game->info->stats_allys[i - 1]->price));
        } else {
            sfText_setColor(game->text[i]->text, sfGreen);
            sfText_setString(game->text[i]->text,
                    int_to_str(game->info->stats_allys[i - 1]->price));
        }
    }
    if (game->info->stats_miner->price > game->info->money) {
        sfText_setColor(game->text[BUY_MINER]->text, sfRed);
        sfText_setString(game->text[BUY_MINER]->text,
                int_to_str(game->info->stats_miner->price));
    } else {
        sfText_setColor(game->text[BUY_MINER]->text, sfGreen);
        sfText_setString(game->text[BUY_MINER]->text,
                int_to_str(game->info->stats_miner->price));
    }
}

void update_upgrade(gui_t *game)
{
    for (int i = UP_KNIGHT; i <= UP_WIZARD; i++) {
        if (game->info->stats_allys[i - 6]->lvl == 3) {
            sfText_setString(game->text[i]->text, "Max");
            sfText_setCharacterSize(game->text[i]->text, 18);
            sfText_setColor(game->text[i]->text, sfBlue);
        } else if (game->info->stats_allys[i - 6]->upgrade >
                                                    game->info->money) {
            sfText_setColor(game->text[i]->text, sfRed);
            sfText_setString(game->text[i]->text,
                    int_to_str(game->info->stats_allys[i - 6]->upgrade));
        } else {
            sfText_setColor(game->text[i]->text, sfGreen);
            sfText_setString(game->text[i]->text,
                    int_to_str(game->info->stats_allys[i - 6]->upgrade));
        }
    }
}

void update_upgrade_miner(gui_t *game)
{
    if (game->info->stats_miner->lvl == 3) {
        sfText_setString(game->text[UP_MINER]->text, "Max");
        sfText_setCharacterSize(game->text[UP_MINER]->text, 18);
        sfText_setColor(game->text[UP_MINER]->text, sfBlue);
    } else if (game->info->stats_miner->upgrade > game->info->money) {
        sfText_setColor(game->text[UP_MINER]->text, sfRed);
        sfText_setString(game->text[UP_MINER]->text,
                int_to_str(game->info->stats_miner->upgrade));
    } else {
        sfText_setColor(game->text[UP_MINER]->text, sfGreen);
        sfText_setString(game->text[UP_MINER]->text,
                int_to_str(game->info->stats_miner->upgrade));
        }
}

void update_text_battle(gui_t *game)
{
    sfText_setString(game->text[MONEY]->text, int_to_str(game->info->money));
    update_buy(game);
    update_upgrade(game);
    update_upgrade_miner(game);
}