/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** settings
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int s_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
            b_on_off_music(game, game->object[B_ON_OFF_MUSIC], e.mouseButton);
            b_on_off_sound(game, game->object[B_ON_OFF_SOUND], e.mouseButton);
            b_plus_music(game, game->object[B_PLUS], e.mouseButton);
            b_minus_music(game, game->object[B_MINUS], e.mouseButton);
            button_x2(game, game->object[B_RES1], e.mouseButton);
            button_x4(game, game->object[B_RES2], e.mouseButton);
            button_x8(game, game->object[B_RES3], e.mouseButton);
        } else
            game->info->mouse->click = FALSE;
        game->info->mouse->position =
        sfMouse_getPositionRenderWindow(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->scene = game->info->last_scene;
        }
    }
    return (1);
}

int s_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = BG_SETTINGS; i <= B_RES3; i++) {
        displayer(game->window, game->object[i]);
    }
    return (1);
}

int s_update(gui_t *game)
{
    for (int i = VOLUME; i <= B_RES3; i++)
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    sfSprite_setScale(game->object[B_BACK]->sprite,
                        game->object[B_BACK]->scale);
    move_parallax(game);
    b_plus_mouse(game, game->object[B_PLUS]);
    b_minus_mouse(game, game->object[B_MINUS]);
    button_back(game, game->object[B_BACK]);
    return (1);
}

int loop_settings2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!s_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_settings(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!s_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!s_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_settings2(game)) {
        return (0);
    }
    return (1);
}