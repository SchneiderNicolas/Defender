/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

static const char *TEXTURES[NB_TEXTURES] = {
        "./assets/allys/knight_shop.png",
        "./assets/allys/archer_shop.png",
        "./assets/allys/king_shop.png",
        "./assets/allys/wizard_shop.png",
        "./assets/allys/miner_shop.png",
        "./assets/back_game.png",
        "./assets/Settings.png",
        "./assets/Volume.png",
        "./assets/ButtonOnOff.png",
        "./assets/ButtonOnOff.png",
        "./assets/ButtonPlus.png",
        "./assets/ButtonMinus.png",
        "./assets/ButtonBack.png",
        "./assets/ButtonRes.png",
        "./assets/ButtonRes.png",
        "./assets/ButtonRes.png",
        "./assets/Parallax1.png",
        "./assets/Parallax1.png",
        "./assets/Parallax2.png",
        "./assets/Parallax2.png",
        "./assets/Parallax3.png",
        "./assets/Parallax3.png",
        "./assets/Parallax4.png",
        "./assets/Parallax4.png",
        "./assets/Parallax5.png",
        "./assets/Parallax5.png",
        "./assets/allys/knight_idle.png",
        "./assets/allys/knight_attack.png",
        "./assets/allys/knight_death.png",
        "./assets/allys/archer_idle.png",
        "./assets/allys/archer_attack.png",
        "./assets/allys/archer_death.png",
        "./assets/allys/king_idle.png",
        "./assets/allys/king_attack.png",
        "./assets/allys/king_death.png",
        "./assets/allys/wizard_idle.png",
        "./assets/allys/wizard_attack.png",
        "./assets/allys/wizard_death.png",
        "./assets/allys/miner_idle.png",
        "./assets/allys/miner_attack.png",
        "./assets/allys/miner_walk.png",
        "./assets/Menu.png",
        "./assets/ButtonPlay.png",
        "./assets/ButtonSettings.png",
        "./assets/ButtonRules.png",
        "./assets/ButtonQuit.png",
        "./assets/Level.png",
        "./assets/Level1.png",
        "./assets/Level2.png",
        "./assets/Level3.png",
        "./assets/Level4.png",
        "./assets/Pause.png",
        "./assets/ButtonMenu.png",
        "./assets/ButtonQuitP.png",
        "./assets/ButtonResume.png",
        "./assets/ButtonSettingsP.png",
        "./assets/enemys/mob_walk_a.png",
        "./assets/enemys/mob_attack_a.png",
        "./assets/enemys/mob_death_a.png",
        "./assets/enemys/mob_walk_b.png",
        "./assets/enemys/mob_attack_b.png",
        "./assets/enemys/mob_death_b.png",
        "./assets/enemys/mob_walk_c.png",
        "./assets/enemys/mob_attack_c.png",
        "./assets/enemys/mob_death_c.png",
        "./assets/enemys/mob_walk_d.png",
        "./assets/enemys/mob_attack_d.png",
        "./assets/enemys/mob_death_d.png",
        "./assets/enemys/mob_walk_e.png",
        "./assets/enemys/mob_attack_e.png",
        "./assets/enemys/mob_death_e.png",
        "./assets/enemys/mob_walk_f.png",
        "./assets/enemys/mob_attack_f.png",
        "./assets/enemys/mob_death_f.png",
        "./assets/enemys/mob_walk_g.png",
        "./assets/enemys/mob_attack_g.png",
        "./assets/enemys/mob_death_g.png",
        "./assets/enemys/mob_walk_h.png",
        "./assets/enemys/mob_attack_h.png",
        "./assets/enemys/mob_death_h.png",
        "./assets/enemys/mob_walk_i.png",
        "./assets/enemys/mob_attack_i.png",
        "./assets/enemys/mob_death_i.png",
        "./assets/enemys/mob_walk_j.png",
        "./assets/enemys/mob_attack_j.png",
        "./assets/enemys/mob_death_j.png",
        "./assets/enemys/mob_walk_l.png",
        "./assets/enemys/mob_attack_l.png",
        "./assets/enemys/mob_death_l.png",
        "./assets/enemys/mob_walk_m.png",
        "./assets/enemys/mob_attack_m.png",
        "./assets/enemys/mob_death_m.png",
        "./assets/enemys/mob_walk_n.png",
        "./assets/enemys/mob_attack_n.png",
        "./assets/enemys/mob_death_n.png",
        "./assets/enemys/mob_walk_o.png",
        "./assets/enemys/mob_attack_o.png",
        "./assets/enemys/mob_death_o.png",
        "./assets/enemys/mob_walk_p.png",
        "./assets/enemys/mob_attack_p.png",
        "./assets/enemys/mob_death_p.png",
        "./assets/enemys/mob_walk_q.png",
        "./assets/enemys/mob_attack_q.png",
        "./assets/enemys/mob_death_q.png",
        "./assets/enemys/mob_walk_r.png",
        "./assets/enemys/mob_attack_r.png",
        "./assets/enemys/mob_death_r.png",
        "./assets/enemys/mob_walk_s.png",
        "./assets/enemys/mob_attack_s.png",
        "./assets/enemys/mob_death_s.png",
        "./assets/enemys/mob_walk_t.png",
        "./assets/enemys/mob_attack_t.png",
        "./assets/enemys/mob_death_t.png",
        "./assets/enemys/mob_walk_u.png",
        "./assets/enemys/mob_attack_u.png",
        "./assets/enemys/mob_death_u.png",
        "./assets/enemys/mob_walk_v.png",
        "./assets/enemys/mob_attack_v.png",
        "./assets/enemys/mob_death_v.png",
        "./assets/enemys/mob_walk_w.png",
        "./assets/enemys/mob_attack_w.png",
        "./assets/enemys/mob_death_w.png",
        "./assets/enemys/mob_walk_x.png",
        "./assets/enemys/mob_attack_x.png",
        "./assets/enemys/mob_death_x.png",
        "./assets/A.png",
        "./assets/Z.png",
        "./assets/E.png",
        "./assets/R.png",
        "./assets/T.png",
        "./assets/ButtonContinue.png",
        "./assets/LevelComplete.png",
        "./assets/YouLose.png",
        "./assets/HP.png",
        "./assets/Arrow.png",
        "./assets/Spell.png",
        "./assets/Rules.png",
        "./assets/RulesLevel1.png",
        "./assets/RulesLevel2.png",
        "./assets/RulesLevel3.png",
        "./assets/ButtonNext.png"
};

int init_images(gui_t *game)
{
    int i = 0;

    game->object = malloc(sizeof(csfml_object_t *) * (NB_TEXTURES + 1));
    if (game->object == NULL)
        return (0);
    for (; i < NB_TEXTURES; i++) {
        game->object[i] = malloc(sizeof(csfml_object_t));
        game->object[i]->sprite = sfSprite_create();
        game->object[i]->texture = sfTexture_createFromFile(TEXTURES[i], NULL);
        game->object[i]->scale = (sfVector2f){1, 1};
        game->object[i]->position = (sfVector2f){0, 0};
        if (!game->object[i]->sprite || !game->object[i]->texture)
            return (0);
        sfSprite_setTexture(game->object[i]->sprite, game->object[i]->texture,
                            sfTrue);
    }
    game->object[i] = NULL;
    return (1);
}