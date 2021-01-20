/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** loop_lose
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int l_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
                b_continue(game, e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int l_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    displayer(game->window, game->object[BG_LOSE]);
    displayer(game->window, game->object[B_CONTINUE]);
    sfRenderWindow_drawText(game->window, game->text[MONEY_END]->text, NULL);
    return (1);
}

int l_update(gui_t *game)
{
    sfSprite_setTextureRect(game->object[BG_LOSE]->sprite,
        game->object[BG_LOSE]->rect);
    sfSprite_setTextureRect(game->object[B_CONTINUE]->sprite,
        game->object[B_CONTINUE]->rect);
    move_parallax(game);
    b_mouse(game, game->object[B_CONTINUE]);
    sfText_setString(game->text[MONEY_END]->text,
        int_to_str(game->info->money));
    return (1);
}

int loop_lose2(gui_t *game)
{
    double elapsed2 = 0;

    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!l_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_lose(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!l_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!l_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_lose2(game)) {
        return (0);
    }
    return (1);
}