/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:58:23 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 20:19:31 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mob(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->m_cnt[i])
	{
		while (g->m_cnt[i][j])
		{
			if (g->m_cnt[i][j] == 'M')
			{
				g->s_x = j * SIZE_TILES;
				g->s_y = i * SIZE_TILES;
				mlx_put_image_to_window
					(g->mlx, g->win, g->img_g, g->s_x, g->s_y);
				mlx_put_image_to_window
					(g->mlx, g->win, g->img_s, g->s_x, g->s_y);
			}
			j++;
		}
		j = 0;
		i ++;
	}	
}

int	manage_mob(t_game *g)
{
	if (find_direction(g) == rand() % 5
		&& get_pass_s(g, g->s_y - SIZE_TILES, g->s_x))
		s_move_u(g);
	else if (find_direction(g) == rand() % 5
		&& get_pass_s(g, g->s_y + SIZE_TILES, g->s_x))
		s_move_d(g);
	else if (find_direction(g) == rand() % 5
		&& get_pass_s(g, g->s_y, g->s_x - SIZE_TILES))
		s_move_l(g);
	else if (find_direction(g) == rand() % 5
		&& get_pass_s(g, g->s_y, g->s_x + SIZE_TILES))
		s_move_r(g);
	if (g->p_x == g->s_x && g->p_y == g->s_y)
	{
		ft_printf("\033[0;31mGAME OVER\033[0m\n");
		close_win(g);
	}
	return (0);
}

int	find_direction(t_game *g)
{
	if (g->m_cnt[g->s_y / SIZE_TILES - 1][g->s_x / SIZE_TILES] == '0'
	|| g->m_cnt[g->s_y / SIZE_TILES - 1][g->s_x / SIZE_TILES] == 'C')
		return (1);
	if (g->m_cnt[g->s_y / SIZE_TILES + 1][g->s_x / SIZE_TILES] == '0'
	|| g->m_cnt[g->s_y / SIZE_TILES + 1][g->s_x / SIZE_TILES] == 'C')
		return (2);
	if (g->m_cnt[g->s_y / SIZE_TILES][g->s_x / SIZE_TILES - 1] == '0'
	|| g->m_cnt[g->s_y / SIZE_TILES][g->s_x / SIZE_TILES - 1] == 'C')
		return (3);
	if (g->m_cnt[g->s_y / SIZE_TILES + 1][g->s_x / SIZE_TILES + 1] == '0'
	|| g->m_cnt[g->s_y / SIZE_TILES + 1][g->s_x / SIZE_TILES + 1] == 'C')
		return (4);
	else
		return (0);
}

int	get_pass_s(t_game *g, int co_y, int co_x)
{
	int	i;
	int	j;

	i = co_y / SIZE_TILES;
	j = co_x / SIZE_TILES;
	if (g->bool_anim == 0 && g->m_cnt[i][j] == 'E')
	{
		return (1);
	}
	if (g->m_cnt[i][j] != '1' && g->m_cnt[i][j] != 'E')
		return (1);
	else
		return (0);
}
