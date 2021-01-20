/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** pause.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int p_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
            b_resume(game, e.mouseButton);
            b_menu(game, e.mouseButton);
            b_settingsp(game, e.mouseButton);
            b_quitp(game, e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int p_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = BG_PAUSE; i <= B_SETTINGSP; i++) {
        displayer(game->window, game->object[i]);
    }
    return (1);
}

int p_update(gui_t *game)
{
    for (int i = BG_PAUSE; i <= B_SETTINGSP; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    }
    move_parallax(game);
    for (int i = B_MENU; i <= B_SETTINGSP; i++) {
        b_mouse(game, game->object[i]);
    }
    return (1);
}

int loop_pause2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!p_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_pause(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!p_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!p_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_pause2(game)) {
        return (0);
    }
    return (1);
}