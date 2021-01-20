/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** scene win
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int w_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
                b_continue_win(game, e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int w_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    displayer(game->window, game->object[BG_WIN]);
    displayer(game->window, game->object[B_CONTINUE]);
    sfRenderWindow_drawText(game->window, game->text[MONEY_END]->text, NULL);
    return (1);
}

int w_update(gui_t *game)
{
    sfSprite_setTextureRect(game->object[BG_WIN]->sprite,
        game->object[BG_WIN]->rect);
    sfSprite_setTextureRect(game->object[B_CONTINUE]->sprite,
        game->object[B_CONTINUE]->rect);
    move_parallax(game);
    b_mouse(game, game->object[B_CONTINUE]);
    sfText_setString(game->text[MONEY_END]->text,
        int_to_str(game->info->money));
    return (1);
}

int loop_win2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!w_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_win(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!w_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!w_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_win2(game)) {
        return (0);
    }
    return (1);
}