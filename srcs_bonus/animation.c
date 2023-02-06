/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:44:36 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 20:15:54 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_coin(t_game *g)
{
	g->c_i = 0;
	g->c_j = 0;
	g->c_x = 0;
	g->c_y = 0;
	while (g->m_cnt[g->c_i])
	{
		while (g->m_cnt[g->c_i][g->c_j])
		{
			if (g->m_cnt[g->c_i][g->c_j] == 'C')
			{
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_g, g->c_x, g->c_y);
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_m, g->c_x, g->c_y);
			}
			g->c_x += SIZE_TILES;
			g->c_j ++;
		}
		g->c_j = 0;
		g->c_i += 1;
		g->c_x = 0;
		g->c_y += SIZE_TILES;
	}
	return (0);
}	

int	frame_manage(t_game *g)
{
	if (!(g->frame % 750))
	{
		coins(g);
		mlx_put_image_to_window(g->mlx, g->win, g->img_e, g->d_wdt, g->d_hgt);
		if (g->p_x == g->d_wdt && g->p_y == g->d_hgt)
			mlx_put_image_to_window
				(g->mlx, g->win, g->img_c, g->p_x, g->p_y);
	}
	if (!(g->frame % 2000))
		manage_mob(g);
	if (g->nbr_m_take == g->start_coin && !(g->frame % 750)
		&& g->bool_anim == 1)
		door_animation(g);
	if (g->bool_anim == 0 && g->p_y == g->d_hgt && g->p_x == g->d_wdt)
	{
		ft_printf ("\033[36;01mWIN\033[00m\n");
		free_all(g);
		system("leaks so_long");
		exit(0);
	}
	g->frame ++;
	return (0);
}

int	coins(t_game *g)
{
	char	*path;

	path = ft_strjoin(ft_strdup("img/Money/coin"), ft_strdup(g->index_m));
	path = ft_strjoin(path, ft_strdup(".xpm"));
	g->img_m = mlx_xpm_file_to_image(g->mlx, path, &g->c_i, &g->c_j);
	if (g->index_m[0] == '8')
		g->index_m[0] = '0';
	g->index_m[0]++;
	refresh_coins(g);
	put_coin(g);
	if (path)
		free(path);
	return (0);
}

int	refresh_coins(t_game *g)
{
	if (g->m_cnt[g->p_y / SIZE_TILES][g->p_x / SIZE_TILES] == 'C')
	{
		g->m_cnt[g->p_y / SIZE_TILES][g->p_x / SIZE_TILES] = '0';
		g->nbr_m_take++;
		return (1);
	}
	return (0);
}
