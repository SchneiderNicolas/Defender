##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile Defender
##

REDDARK=\033[31;2m
RED=\033[31;1m
GREEN=\033[32;1m
YEL=\033[33;1m
BLUE=\033[34;1m
PINK=\033[35;1m
CYAN=\033[36;1m
RES=\033[0m

SRC =	src/main.c 							\
		src/init/init_gui.c 				\
		src/init/init_image.c 				\
		src/init/init_music.c 				\
		src/init/init_battle.c 				\
		src/init/init_stats_enemy.c			\
		src/init/init_stats_ally.c			\
		src/init/init_stats_miner.c			\
		src/init/init_level.c 				\
		src/init/init_settings.c			\
		src/init/init_menu.c				\
		src/init/init_pause.c				\
		src/init/init_board.c				\
		src/init/init_select_level.c		\
		src/scenes/menu.c 					\
		src/scenes/scene_manager.c 			\
		src/scenes/battle.c					\
		src/scenes/settings.c				\
		src/scenes/select_level.c			\
		src/scenes/pause.c					\
		src/utils/display.c					\
		src/utils/parallax.c				\
		src/utils/move_rect.c				\
		src/utils/button_music.c			\
		src/utils/button_sound.c			\
		src/utils/button_volume.c			\
		src/utils/button_res.c				\
		src/utils/button_back.c				\
		src/utils/clone_class.c				\
		src/utils/clone_allys.c				\
		src/utils/add_node.c				\
		src/utils/lvl_and_stats_up.c		\
		src/utils/button_mouse.c			\
		src/utils/button_play.c				\
		src/utils/button_quit.c				\
		src/utils/button_settings.c			\
		src/utils/button_pause.c			\
		src/utils/update_board_info.c		\
		src/utils/getline.c					\
		src/utils/disp_update_battle.c		\
		src/utils/check_pos_mouse.c			\
		src/utils/set_pos_allys.c			\
		src/utils/b_level.c					\
		src/utils/b_mouse_level.c			\
		src/utils/clone_mob_a_b_c_d_e.c		\
		src/utils/clone_mob_f_g_h_i_j.c		\
		src/utils/clone_mob_k_l_m_n_o.c		\
		src/utils/clone_mob_p_q_r_s_t.c		\
		src/utils/clone_mob_u_v_w_x.c		\
		src/utils/check_attack.c			\
		src/utils/give_stats.c				\
		src/utils/remove_money.c			\
		src/utils/check_price.c				\
		src/utils/my_str_to_word_array.c	\
		src/utils/my_get_nbr.c				\
		src/utils/move_miner.c				\
		src/init/init_text.c				\
		src/utils/int_to_str.c				\
		src/utils/check_distroy.c			\
		src/utils/update_upgrade_buy.c		\
		src/init/init_lose.c				\
		src/scenes/lose.c					\
		src/utils/b_continue.c				\
		src/init/init_win.c					\
		src/scenes/win.c					\
		src/utils/update_hp.c				\
		src/utils/check_distroy_shot.c		\
		src/utils/b_update_part.c			\
		src/utils/create_shot.c				\
		src/utils/which_statement.c			\
		src/utils/write_in_file.c			\
		src/utils/my_strlen.c				\
		src/utils/nb_unlocked_level.c		\
		src/utils/clone_miner_lvl.c			\
		src/utils/free_node.c				\
		src/init/init_rules.c				\
		src/scenes/rules.c					\
		src/utils/button_rules.c			\
		src/utils/b_rules.c 				\
		src/utils/free_stats.c				\
		src/utils/my_putstr.c

OBJ = $(SRC:.c=.o)

NAME = my_defender


$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g
	@echo -e "$(RED)$(NAME) $(GREEN)[✘]$(RES)"

all: 	$(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re:		fclean all