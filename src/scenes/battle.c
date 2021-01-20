/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game.c
*/

#include "../../include/game.h"
#include "../../include/prototype.h"

int b_event(gui_t *game)
{
    sfEvent e;
    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonReleased) {
            game->info->mouse->click = TRUE;
            level_up(e.mouseButton, game->object, game);
            level_up_miner(e.mouseButton, game->object, game);
        } else
            game->info->mouse->click = FALSE;
        if (e.type == sfEvtKeyPressed) {
            clone_allys(game);
        }
        game->info->mouse->position =
        sfMouse_getPositionRenderWindow(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->scene = PAUSE;
        }
    }
    return (1);
}

int b_display(gui_t *game)
{
    display_shop(game);
    for (list_allys_t *tmp = game->list_allys; tmp != NULL; tmp = tmp->next) {
        displayer(game->window, tmp->object[tmp->status]);
    }
    for (list_miner_t *tmp = game->list_miner; tmp != NULL; tmp = tmp->next) {
        displayer(game->window, tmp->object[tmp->status]);
    }
    for (list_enemy_t *tmp = game->list_enemy; tmp != NULL; tmp = tmp->next) {
        displayer(game->window, tmp->object[tmp->status]);
    }
    for (int i = MONEY; i <= UP_MINER; i++) {
        sfRenderWindow_drawText(game->window, game->text[i]->text, NULL);
    }
    displayer(game->window, game->object[HP]);
    for (list_shot_t *tmp = game->list_shot; tmp != NULL; tmp = tmp->next) {
        displayer(game->window, tmp->object);
        tmp->object->position.x += 10;
    }
    return (1);
}

int b_update(gui_t *game)
{
    reset_pos(game);
    update_rect_shop_allys(game);
    update_rect_shop_enemy(game);
    update_rect_attack_distance(game);
    update_hp(game);
    update_text_battle(game);
    move_miner(game);
    set_texture_shop_board(game);
    check_distroy_allys(game);
    check_distroy_enemys(game);
    if (game->info->hp == 8)
        game->info->scene = LOSE;
    return (1);
}

int loop_battle2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!b_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_battle(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!b_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!b_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_battle2(game)) {
        return (0);
    }
    if (game->list_enemy == NULL)
        game->info->scene = WIN;
    return (1);
}