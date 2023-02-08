/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:50:39 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/08 15:41:30 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE_TILES 32
# define BUFFER_SIZE 1
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game{
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_g;
	void	*img_c;
	void	*img_m;
	void	*img_e;
	void	*img_s;
	char	*index_m;
	char	*index_d;
	int		frame;
	int		nbr_m_take;
	int		m_fd;
	int		m_rsl;
	int		m_hgt;
	int		m_wdt;
	char	*m_name;
	int		d_hgt;
	int		d_wdt;
	int		m_hgt_line;
	int		m_wdt_line;
	char	**m_cnt;
	char	**m_pf;
	char	*m_carac;
	int		start_coin;
	int		bool_anim;
	int		bool_e;
	int		bool_c;
	int		bool_p;
	int		bool_s;
	int		s_x;
	int		s_y;
	int		n_move;
	int		p_x;
	int		p_y;
	int		p_move;	
	int		c_x;
	int		c_y;
	int		c_i;
	int		c_j;
	int		w_max_s;
	int		w_min_s;

}				t_game;

void	initialisation(t_game *g);
int		player_move(int keycode, t_game *g);
int		fill_map(t_game *g);
void	find_p(t_game *g);
int		up_move(t_game *g);
int		down_move(t_game *g);
int		left_move(t_game *g);
int		right_move(t_game *g);
int		get_pass(t_game *g, int co_y, int co_x);
int		coins(t_game *g);
int		refresh_coins(t_game *g);
int		fill_map2(t_game *g);
int		refresh_coins(t_game *g);
int		frame_manage(t_game *g);
void	get_map(t_game *g);
void	pathfinding(t_game *g);
void	get_map_pathfinding(t_game *g);
int		pathfinding_verif(t_game *g);
int		v_map(t_game *g, int i, int j);
void	refresh_map(t_game *g, int i, int j);
void	count_money(t_game *g);
int		door_animation(t_game *g);
int		verif_border(t_game *g);
int		verif_border2(t_game *g);
int		verif_line(t_game *g);
int		general(t_game *g);
int		exit_g(t_game *g);
int		verif_content(t_game *g);
int		is_char(t_game *g, char c);
int		verif_min(t_game *g);
int		score(t_game *g);
void	free_all(t_game *g);
int		close_win(t_game *g);
void	free_error(t_game *g);
int		general2(t_game *g);
int		manage_mob(t_game *g);
void	init_mob(t_game *g);
void	s_move_r(t_game *g);
void	s_move_l(t_game *g);
void	s_move_d(t_game *g);
void	s_move_u(t_game *g);
int		find_direction(t_game *g);
int		verif_mob(t_game *g);
int		verif_map_name(char **argv);
void	get_map2(t_game *g, int i, char *line, char *map_temp);
int		get_pass_s(t_game *g, int co_y, int co_x);
void	verif_m_cnt(t_game *g);
void	verif_launch(char **argv);
void	verif_m_cnt_b(t_game *g, int argc);
#endif