/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** scene rule
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int r_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
            b_next(game, game->object[B_NEXT], e.mouseButton);
            b_back(game, game->object[B_BACK], e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->rules = 1;
            game->info->scene = MENU;
        }
    }
    return (1);
}

int r_display(gui_t *game)
{
    if (game->info->rules == 1) {
        displayer(game->window, game->object[BG_RULES]);
    }
    if (game->info->rules == 2) {
        displayer(game->window, game->object[BG_RULES1]);
    }
    if (game->info->rules == 3) {
        displayer(game->window, game->object[BG_RULES2]);
    }
    if (game->info->rules == 4) {
        displayer(game->window, game->object[BG_RULES3]);
    }
    displayer(game->window, game->object[B_BACK]);
    if (game->info->rules != 4) {
        displayer(game->window, game->object[B_NEXT]);
    }
    return (1);
}

int r_update(gui_t *game)
{
    button_back_rules(game, game->object[B_BACK]);
    button_next_rules(game, game->object[B_NEXT]);
    return (1);
}

int loop_rules2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!r_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_rules(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!r_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!r_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_rules2(game)) {
        return (0);
    }
    return (1);
}