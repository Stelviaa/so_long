/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:03:47 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 14:23:02 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initialisation(t_game *g)
{
	int	a;
	int	b;

	g->mlx = mlx_init();
	g->index_m = ft_strdup("1");
	g->index_d = ft_strdup("1");
	g->bool_anim = 1;
	g->frame = 0;
	g->n_move = SIZE_TILES;
	g->p_move = 0;
	g->win = mlx_new_window(g->mlx, g->m_wdt, g->m_hgt, "world door");
	g->img_g = mlx_xpm_file_to_image(g->mlx, "img/Tiles/ground.xpm", &a, &b);
	g->img_w = mlx_xpm_file_to_image(g->mlx, "img/Tiles/wall.xpm", &a, &b);
	g->img_c = mlx_xpm_file_to_image(g->mlx, "img/Player/player1.xpm", &a, &b);
	g->img_e = mlx_xpm_file_to_image(g->mlx, "img/Door/door.xpm", &a, &b);
	coins(g);
	fill_map(g);
	fill_map2(g);
	find_p(g);
	count_money(g);
}

int	player_move(int keycode, t_game *g)
{
	if (get_pass(g, g->p_y - SIZE_TILES, g->p_x) && keycode == 13)
	{
		g->p_move += up_move(g);
		ft_printf("Score:\033[0;33m%d\033[0m\n", g->p_move);
	}
	if (get_pass(g, g->p_y + SIZE_TILES, g->p_x) && keycode == 1)
	{
		g->p_move += down_move(g);
		ft_printf("Score:\033[0;33m%d\033[0m\n", g->p_move);
	}
	if (get_pass(g, g->p_y, g->p_x + SIZE_TILES) && keycode == 2)
	{
		g->p_move += right_move(g);
		ft_printf("Score:\033[0;33m%d\033[0m\n", g->p_move);
	}
	if (get_pass(g, g->p_y, g->p_x - SIZE_TILES) && keycode == 0)
	{
		g->p_move += left_move(g);
		ft_printf("Score:\033[0;33m%d\033[0m\n", g->p_move);
	}
	if (keycode == 53)
		close_win(g);
	return (0);
}

void	count_money(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	g->start_coin = 0;
	while (g->m_cnt[++i])
	{
		while (g->m_cnt[i][++j])
		{
			if (g->m_cnt[i][j] == 'C')
			{
				g->start_coin++;
			}
		}
		j = -1;
	}
}

void	free_all(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->m_hgt_line)
	{
		if (g->m_cnt)
			free(g->m_cnt[i]);
		g->m_cnt[i] = NULL;
	}
	i = -1;
	while (++i < g->m_hgt_line)
	{
		if (g->m_pf[i])
			free(g->m_pf[i]);
		g->m_pf[i] = NULL;
	}
	mlx_destroy_window(g->mlx, g->win);
	if (g->index_m)
		free(g->index_m);
	if (g->index_d)
		free(g->index_d);
}
