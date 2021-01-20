/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** game.h for Defender
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "game.h"

// init
int init_music(gui_t *);
int reset_pos(gui_t *);
int init_info(gui_t *game);
int init_battle(gui_t *game);
int init_level(gui_t *game);
int init_stats_ally(gui_t *game);
int init_stats_miner(gui_t *game);

// sceneManager
int loop_global(gui_t *);

//tools
void displayer(sfRenderWindow *, csfml_object_t *);
void move_background(csfml_object_t *, float, float);
void move_parallax(gui_t *);
void move_rect(csfml_object_t *);
list_allys_t *add_node(list_allys_t *, list_allys_t *);
void up_stats(stats_t *);
void level_up(sfMouseButtonEvent, csfml_object_t **, gui_t *);
void level_up_miner(sfMouseButtonEvent, csfml_object_t **, gui_t *);
void update_board_info(gui_t *, csfml_object_t *, int);
char *get_line(FILE *);
list_miner_t *add_node_miner(list_miner_t *, list_miner_t *);
void display_shop(gui_t *);
void set_texture_shop_board(gui_t *);
int check_pos_mouse(gui_t *);
void set_pos_ally(gui_t *, list_allys_t *, int, int);
list_enemy_t *add_node_enemy(list_enemy_t *head, list_enemy_t *node);
void check_attack(gui_t *);
int my_getnbr(char const *);
char **my_str_to_word_array(char *, char);
int my_intlen(int);
char *int_to_str(int);
void update_hp(gui_t *);
list_shot_t *add_node_shot(list_shot_t *, list_shot_t *);
void update_rect_shop_allys(gui_t *);
void update_rect_shop_enemy(gui_t *);
void create_shot(gui_t *, list_allys_t *);
void which_statement(list_allys_t *, list_enemy_t *, sfFloatRect, gui_t *);
void update_rect_attack_distance(gui_t *);
void check_distroy_shot(gui_t *, sfFloatRect, list_enemy_t *);
int write_in_save(char *);
unsigned int my_strlen(char const *str);
int nb_unlocked_level(void);
void my_putstr(char const *);

//buttons
void b_on_off_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_on_off_sound(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_plus_mouse(gui_t *, csfml_object_t *);
void b_minus_mouse(gui_t *, csfml_object_t *);
void b_plus_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_minus_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x2(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x4(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x8(gui_t *, csfml_object_t *, sfMouseButtonEvent);
int button_back(gui_t *, csfml_object_t *);
void b_quit(gui_t *, sfMouseButtonEvent);
void b_play(gui_t *, sfMouseButtonEvent);
void b_settings(gui_t *, sfMouseButtonEvent);
void b_mouse(gui_t *, csfml_object_t *);
void b_resume(gui_t *, sfMouseButtonEvent);
void b_menu(gui_t *, sfMouseButtonEvent);
void b_settingsp(gui_t *, sfMouseButtonEvent);
void b_quitp(gui_t *, sfMouseButtonEvent);
void give_stats_miner(stats_miner_t *, list_miner_t *);
void give_stats_allys(stats_t *, list_allys_t *);
void give_stats_enemy(stats_enemy_t *, list_enemy_t *);
void b_continue(gui_t *, sfMouseButtonEvent);
void b_continue_win(gui_t *, sfMouseButtonEvent);
int button_back_rules(gui_t *, csfml_object_t *);
int button_next_rules(gui_t *, csfml_object_t *);
void b_next(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_back(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_rules(gui_t *, sfMouseButtonEvent);

// destroy
void check_distroy_shot(gui_t *, sfFloatRect, list_enemy_t *);
void check_distroy_allys(gui_t *);
void check_distroy_enemys(gui_t *);
void free_node(list_allys_t *);
void free_node_enemy(list_enemy_t *);
void free_stats_allys(gui_t *);
void free_list_enemy(list_enemy_t *);

// clone
int clone_allys(gui_t *);
void clone_knight(gui_t *);
void clone_archer(gui_t *);
void clone_king(gui_t *);
void clone_wizard(gui_t *);
void clone_miner(gui_t *);
void clone_miner_lvl(gui_t *, list_miner_t *, int);
int clone_mob_a(gui_t *, int, int);
int clone_mob_b(gui_t *, int, int);
int clone_mob_c(gui_t *, int, int);
int clone_mob_d(gui_t *, int, int);
int clone_mob_e(gui_t *, int, int);
int clone_mob_f(gui_t *, int, int);
int clone_mob_g(gui_t *, int, int);
int clone_mob_h(gui_t *, int, int);
int clone_mob_i(gui_t *, int, int);
int clone_mob_j(gui_t *, int, int);
int clone_mob_k(gui_t *, int, int);
int clone_mob_l(gui_t *, int, int);
int clone_mob_m(gui_t *, int, int);
int clone_mob_n(gui_t *, int, int);
int clone_mob_o(gui_t *, int, int);
int clone_mob_p(gui_t *, int, int);
int clone_mob_q(gui_t *, int, int);
int clone_mob_r(gui_t *, int, int);
int clone_mob_s(gui_t *, int, int);
int clone_mob_t(gui_t *, int, int);
int clone_mob_u(gui_t *, int, int);
int clone_mob_v(gui_t *, int, int);
int clone_mob_w(gui_t *, int, int);
int clone_mob_x(gui_t *, int, int);

//level
void b_level1(gui_t *, sfMouseButtonEvent);
void b_level2(gui_t *, sfMouseButtonEvent);
void b_level3(gui_t *, sfMouseButtonEvent);
void b_level4(gui_t *, sfMouseButtonEvent);
void b_mouse_level(gui_t *, csfml_object_t **);

//money
int check_price_knight(gui_t *);
int check_price_archer(gui_t *);
int check_price_king(gui_t *);
int check_price_wizard(gui_t *);
int check_price_miner(gui_t *);
void remove_money_knight(gui_t *);
void remove_money_archer(gui_t *);
void remove_money_king(gui_t *);
void remove_money_wizard(gui_t *);
void remove_money_miner(gui_t *);

//miner
void move_miner_right(list_miner_t *);
void move_miner_mine(list_miner_t *);
void move_miner_left(list_miner_t *, gui_t *);
void move_miner(gui_t *);

//text

void update_buy(gui_t *);
void update_upgrade(gui_t *);
void update_upgrade_miner(gui_t *);
void update_text_battle(gui_t *);

#endif //PROTOTYPE_H
