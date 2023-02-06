/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:52:47 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 14:13:42 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_border(t_game *g)
{
	int	i;

	i = -1;
	while (g->m_cnt[0][++i])
	{
		if (g->m_cnt[0][i] != '1')
			return (0);
	}
	i = -1;
	while (g->m_cnt[g->m_hgt_line - 1][++i])
	{
		if (g->m_cnt[g->m_hgt_line - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	verif_border2(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->m_hgt_line - 1)
	{
		if (g->m_cnt[i][0] != '1')
			return (0);
	}
	i = -1;
	while (++i < g->m_hgt_line)
	{
		if (g->m_cnt[i][g->m_wdt_line - 1] != '1')
			return (0);
	}
	return (1);
}

int	verif_content(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->m_carac = malloc(sizeof(char) * 7);
	g->m_carac[0] = 'P';
	g->m_carac[1] = 'E';
	g->m_carac[2] = '0';
	g->m_carac[3] = '1';
	g->m_carac[4] = 'C';
	g->m_carac[5] = 'M';
	g->m_carac[6] = '\0';
	while (g->m_cnt[i])
	{
		while (g->m_cnt[i][++j])
			if (!is_char(g, g->m_cnt[i][j]))
				return (0);
		j = 0;
		i ++;
	}
	if (g->m_carac)
		free(g->m_carac);
	return (1);
}

int	verif_line(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < g->m_hgt_line - 1)
	{
		while (g->m_cnt[j][i])
			i ++;
		if (i != g->m_wdt_line)
			return (0);
		i = 0;
	}
	return (1);
}

int	general(t_game *g)
{
	get_map_pathfinding(g);
	if (!verif_border(g) || !verif_border2(g))
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("The map isn't surrounded by walls\n");
		free_error(g);
		exit(0);
	}
	if (!verif_line(g))
	{
		ft_printf("\033[0;31mError\033[0m\nThe map isn't rectangular\n");
		free_error(g);
		exit(0);
	}
	return (1);
}
