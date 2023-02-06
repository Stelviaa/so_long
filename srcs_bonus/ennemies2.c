/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:41:24 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 20:16:12 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	s_move_r(t_game *g)
{	
	int	a;
	int	b;

	g->s_x += SIZE_TILES;
	g->img_s = mlx_xpm_file_to_image(g->mlx, "img/Mob/mob_r.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->s_x, g->s_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->s_x - SIZE_TILES, g->s_y);
	mlx_put_image_to_window(g->mlx, g->win, g->img_s, g->s_x, g->s_y);
}

void	s_move_l(t_game *g)
{	
	int	a;
	int	b;

	g->s_x -= SIZE_TILES;
	g->img_s = mlx_xpm_file_to_image(g->mlx, "img/Mob/mob_l.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->s_x, g->s_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, (g->s_x + SIZE_TILES), g->s_y);
	mlx_put_image_to_window(g->mlx, g->win, g->img_s, g->s_x, g->s_y);
}

void	s_move_u(t_game *g)
{	
	int	a;
	int	b;

	g->s_y -= SIZE_TILES;
	g->img_s = mlx_xpm_file_to_image(g->mlx, "img/Mob/mob_l.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->s_x, g->s_y);
	mlx_put_image_to_window
	(g->mlx, g->win, g->img_g, g->s_x, g->s_y + SIZE_TILES);
	mlx_put_image_to_window(g->mlx, g->win, g->img_s, g->s_x, g->s_y);
}

void	s_move_d(t_game *g)
{	
	int	a;
	int	b;

	g->s_y += SIZE_TILES;
	g->img_s = mlx_xpm_file_to_image(g->mlx, "img/Mob/mob_l.xpm", &a, &b);
	mlx_put_image_to_window(g->mlx, g->win, g->img_g, g->s_x, g->s_y);
	mlx_put_image_to_window
		(g->mlx, g->win, g->img_g, g->s_x, g->s_y - SIZE_TILES);
	mlx_put_image_to_window(g->mlx, g->win, g->img_s, g->s_x, g->s_y);
}
