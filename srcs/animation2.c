/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:44 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 14:14:44 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	door_animation(t_game *g)
{
	char	*line;
	int		a;
	int		b;

	if (g->nbr_m_take == g->start_coin)
	{
		line = ft_strjoin(ft_strdup("img/Door/door"), ft_strdup(g->index_d));
		line = ft_strjoin(line, ft_strdup(".xpm"));
		g->img_e = mlx_xpm_file_to_image(g->mlx, line, &a, &b);
		mlx_put_image_to_window(g->mlx, g->win, g->img_e, g->d_wdt, g->d_hgt);
		g->index_d[0]++;
		if (line)
			free(line);
	}
	if (g->index_d[0] == ':')
	{
		g->start_coin += 3;
		g->bool_anim = 0;
	}
	return (0);
}
/*
int	score(t_game *g)
{
	char	*line;

	line = ft_strjoin(ft_strdup("SCORE:"), ft_itoa(g->p_move));
	mlx_put_image_to_window(g->mlx, g->win, g->img_w,
		(g->m_wdt_line * SIZE_TILES) - SIZE_TILES * 3,
		(g->m_hgt_line * SIZE_TILES) - SIZE_TILES);
	mlx_put_image_to_window(g->mlx, g->win, g->img_w,
		(g->m_wdt_line * SIZE_TILES) - SIZE_TILES * 2,
		(g->m_hgt_line * SIZE_TILES) - SIZE_TILES);
	mlx_put_image_to_window(g->mlx, g->win, g->img_w,
		(g->m_wdt_line * SIZE_TILES) - SIZE_TILES,
		(g->m_hgt_line * SIZE_TILES) - SIZE_TILES);
	mlx_string_put(g->mlx, g->win,
		(g->m_wdt_line * SIZE_TILES) - SIZE_TILES * 3,
		(g->m_hgt_line * SIZE_TILES) - SIZE_TILES, 10011684, line);
	if (line)
		free(line);
	return (0);
}*/
