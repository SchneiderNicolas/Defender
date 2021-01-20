/*
** EPITECH PROJECT, 2020
** My defender
** File description:
** main.c
*/

#include "../include/game.h"
#include "../include/macro.h"
#include "../include/init.h"
#include "../include/prototype.h"

int initiation(gui_t *game)
{
    for (int i = 0; i < NB_INIT; i++)
        if (!INIT[i].tor(game))
            return (0);
    return (1);
}

void destroy_sprite(gui_t *game)
{
    for (int i = 0; i < NB_TEXTURES; i++) {
        sfSprite_destroy(game->object[i]->sprite);
        sfTexture_destroy(game->object[i]->texture);
    }
}

int destroy(gui_t *game)
{
    for (int i = 0; i < NB_MUSIC; i++) {
        sfMusic_destroy(game->music[i]);
    }
    destroy_sprite(game);
    return (1);
}

int main(int argc, char **argv, char **env)
{
    gui_t *game = NULL;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("MY DEFENDER\n\n");
        my_putstr("USAGE\n ./my_defender\n\n\n");
        my_putstr("OPTIONS\n -h");
        my_putstr("                print the usage and quit.\n");
        my_putstr("\n\n                HAVE FUN !\n\n");
        return (0);
    }
    if (!*env || argc != 1)
        return (84);
    game = malloc(sizeof(gui_t));
    if (!game || !initiation(game) || !loop_global(game) || !destroy(game))
        return (84);
    return (0);
}