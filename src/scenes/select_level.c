/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** select level
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int sl_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        b_level1(game, e.mouseButton);
        b_level2(game, e.mouseButton);
        b_level3(game, e.mouseButton);
        b_level4(game, e.mouseButton);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
        } else
            game->info->mouse->click = FALSE;
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->scene = MENU;
        }
    }
    return (1);
}

int sl_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = BG_LEVEL; i <= LEVEL4; i++) {
        displayer(game->window, game->object[i]);
    }
    displayer(game->window, game->object[B_BACK]);
    return (1);
}

int sl_update(gui_t *game)
{
    for (int i = BG_LEVEL; i <= LEVEL4 ; i++)
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    move_parallax(game);
    for (int i = LEVEL1; i <= LEVEL4; i++)
        b_mouse_level(game, game->object);
    button_back(game, game->object[B_BACK]);
    return (1);
}

int loop_select_level2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!sl_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_select_level(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!sl_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!sl_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_select_level2(game)) {
        return (0);
    }
    return (1);
}