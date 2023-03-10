/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:50:05 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/08 18:30:35 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game *g)
{
	int		i;
	char	*line;
	char	*map_temp;

	g->m_fd = open(g->m_name, O_RDONLY);
	if (g->m_fd == -1)
	{
		ft_printf("\033[0;31mError\033[0m\nMap name not recognized\n");
		free_error(g);
		exit(0);
	}
	line = get_next_line(g->m_fd);
	i = 0;
	map_temp = ft_calloc(1, 1);
	g->m_wdt_line = ft_strlen(line) - 1;
	while (line && line[0] != '\n')
	{
		map_temp = ft_strjoin(map_temp, line);
		line = get_next_line(g->m_fd);
		i ++;
	}
	close (g->m_fd);
	if (g->m_fd == -1)
		exit(0);
	get_map2(g, i, line, map_temp);
}

int	fill_map(t_game *g)
{
	g->c_i = 0;
	g->c_j = 0;
	g->c_x = 0;
	g->c_y = 0;
	while (g->m_cnt[g->c_i])
	{
		while (g->m_cnt[g->c_i][g->c_j])
		{
			if (g->m_cnt[g->c_i][g->c_j] == '0'
				|| g->m_cnt[g->c_i][g->c_j] == 'C'
				|| g->m_cnt[g->c_i][g->c_j] == 'E')
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_g, g->c_x, g->c_y);
			else if (g->m_cnt[g->c_i][g->c_j] == '1')
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_w, g->c_x, g->c_y);
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

int	fill_map2(t_game *g)
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
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_m, g->c_x, g->c_y);
			if (g->m_cnt[g->c_i][g->c_j] == 'E')
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_e, g->c_x, g->c_y);
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

void	find_p(t_game *g)
{
	g->c_i = 0;
	g->c_j = 0;
	while (g->m_cnt[g->c_i])
	{
		while (g->m_cnt[g->c_i][g->c_j])
		{
			if (g->m_cnt[g->c_i][g->c_j] == 'P')
			{
				g->p_x = g->c_j * SIZE_TILES;
				g->p_y = g->c_i * SIZE_TILES;
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_g, g->p_x, g->p_y);
				mlx_put_image_to_window(
					g->mlx, g->win, g->img_c, g->p_x, g->p_y);
			}
			if (g->m_cnt[g->c_i][g->c_j] == 'E')
			{
				g->d_hgt = g->c_i * SIZE_TILES;
				g->d_wdt = g->c_j * SIZE_TILES;
			}
			g->c_j ++;
		}	
		g->c_j = 0;
		g->c_i += 1;
	}
}

int	main(int argc, char **argv)
{
	t_game	*g;
	int		i;

	i = 0;
	if (argc != 2)
	{	
		ft_printf("\033[0;31mError\033[0m\nBad numbers of arguments");
		exit(0);
	}
	verif_map_name(argv);
	verif_launch(argv);
	g = malloc(sizeof(t_game));
	if (!g)
		return (-1);
	g->m_name = ft_strdup(argv[1]);
	verif_m_cnt(g);
	get_map(g);
	general(g);
	general2(g);
	g->nbr_m_take = 0;
	initialisation(g);
	mlx_loop_hook(g->mlx, frame_manage, g);
	mlx_hook(g->win, 2, 0L, player_move, g);
	mlx_hook(g->win, 17, 0, close_win, g);
	mlx_loop(g->mlx);
}
