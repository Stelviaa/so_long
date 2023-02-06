/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:46:57 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 20:17:15 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_move(t_game *g)
{
	if (g->p_y - SIZE_TILES == g->d_hgt && g->p_x == g->d_wdt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
		mlx_put_image_to_window
		(g->mlx, g->win, g->img_e, g->p_x, g->p_y - SIZE_TILES);
		g->p_y -= SIZE_TILES;
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
		return (1);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->p_x, g->p_y - SIZE_TILES);
	g->p_y -= SIZE_TILES;
	mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
	return (1);
}

int	down_move(t_game *g)
{
	if (g->p_y + SIZE_TILES == g->d_hgt && g->p_x == g->d_wdt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
		mlx_put_image_to_window
		(g->mlx, g->win, g->img_e, g->p_x, g->p_y + SIZE_TILES);
		g->p_y += SIZE_TILES;
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
		return (1);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->p_x, g->p_y + SIZE_TILES);
	g->p_y += SIZE_TILES;
	mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
	return (1);
}

int	left_move(t_game *g)
{
	int	a;
	int	b;

	if (g->p_y == g->d_hgt && g->p_x - SIZE_TILES == g->d_wdt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
		mlx_put_image_to_window
		(g->mlx, g->win, g->img_e, g->p_x - SIZE_TILES, g->p_y);
		g->p_x -= SIZE_TILES;
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
		return (1);
	}
	g->img_c = mlx_xpm_file_to_image
		(g->mlx, "img/Player/player1_l.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->p_x - SIZE_TILES, g->p_y);
	g->p_x -= SIZE_TILES;
	mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
	return (1);
}

int	right_move(t_game *g)
{
	int	a;
	int	b;

	if (g->p_y == g->d_hgt && g->p_x + SIZE_TILES == g->d_wdt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
		mlx_put_image_to_window
		(g->mlx, g->win, g->img_e, g->p_x + SIZE_TILES, g->p_y);
		g->p_x += SIZE_TILES;
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
		return (1);
	}
	g->img_c = mlx_xpm_file_to_image(g->mlx, "img/Player/player1.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->p_x, g->p_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->p_x + SIZE_TILES, g->p_y);
	g->p_x += SIZE_TILES;
	mlx_put_image_to_window(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
	return (1);
}

int	get_pass(t_game *g, int co_y, int co_x)
{
	int	i;
	int	j;

	i = co_y / SIZE_TILES;
	j = co_x / SIZE_TILES;
	if (g->bool_anim == 0 && g->m_cnt[i][j] == 'E')
	{
		return (1);
	}
	if (g->m_cnt[i][j] != '1')
		return (1);
	else
		return (0);
}
