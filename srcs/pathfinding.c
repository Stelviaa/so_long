/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:32:25 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 18:09:52 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_pathfinding(t_game *g)
{
	char	*line;
	char	*map_temp;

	g->m_fd = open(g->m_name, O_RDONLY);
	line = get_next_line(g->m_fd);
	map_temp = ft_calloc(1, 1);
	while (line)
	{
		map_temp = ft_strjoin(map_temp, line);
		line = get_next_line(g->m_fd);
	}
	close (g->m_fd);
	g->m_pf = ft_split(map_temp, '\n');
	if (map_temp)
		free(map_temp);
	if (line)
		free (line);
}

void	refresh_map(t_game *g, int i, int j)
{
	if (g->m_pf[i - 1][j] != '1')
		g->m_pf[i - 1][j] = 'P';
	if (g->m_pf[i][j - 1] != '1')
		g->m_pf[i][j - 1] = 'P';
	if (g->m_pf[i][j + 1] != '1')
		g->m_pf[i][j + 1] = 'P';
	if (g->m_pf[i + 1][j] != '1')
		g->m_pf[i + 1][j] = 'P';
}

int	v_map(t_game *g, int i, int j)
{
	if (g->m_pf[i - 1][j] != 'P' && g->m_pf[i - 1][j] != '1')
		return (0);
	if (g->m_pf[i][j - 1] != 'P' && g->m_pf[i][j - 1] != '1')
		return (0);
	if (g->m_pf[i][j + 1] != 'P' && g->m_pf[i][j + 1] != '1')
		return (0);
	if (g->m_pf[i][j] && g->m_pf[i + 1][j] != 'P' && g->m_pf[i + 1][j] != '1')
		return (0);
	return (1);
}

void	pathfinding(t_game *g)
{
	g->c_i = 0;
	g->c_j = 0;
	while (g->m_pf[g->c_i])
	{
		while (g->m_pf[g->c_i][g->c_j])
		{
			if (g->m_pf[g->c_i][g->c_j] == 'P' && v_map(g, g->c_i, g->c_j) == 0)
			{
				refresh_map(g, g->c_i, g->c_j);
				g->c_i = 0;
				g->c_j = 0;
			}
			g->c_j ++;
		}
		g->c_i++;
		g->c_j = 0;
	}
}

int	pathfinding_verif(t_game *g)
{
	g->c_i = 0;
	g->c_j = 0;
	while (g->m_pf[g->c_i])
	{
		while (g->m_pf[g->c_i][g->c_j])
		{
			if (g->m_pf[g->c_i][g->c_j] == 'E'
				|| g->m_pf[g->c_i][g->c_j] == 'C')
				return (0);
			g->c_j ++;
		}
		g->c_i++;
		g->c_j = 1;
	}
	return (1);
}
