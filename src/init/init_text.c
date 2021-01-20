/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init text
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>

int init_text(gui_t *game)
{
    int i = 0;
    sfFont *font = sfFont_createFromFile("font/saranaigame-bold-webfont.ttf");

    game->text = malloc(sizeof(csfml_text_t *) * (NB_TEXT + 1));
    if (game->text == NULL)
        return 0;
    for (; i < NB_TEXT; i++) {
        game->text[i] = malloc(sizeof(csfml_text_t));
        game->text[i]->text = sfText_create();
        game->text[i]->position = (sfVector2f){0, 0};
        game->text[i]->color = sfWhite;
        game->text[i]->character_size = 20;
        game->text[i]->font = font;
    }
    game->text[i] = NULL;
    return (1);
}