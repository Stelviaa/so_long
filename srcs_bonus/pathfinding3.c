/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:59:51 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/05 18:06:54 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char(t_game *g, char c)
{
	int	i;

	i = 0;
	while (g->m_carac[i])
	{
		if (g->m_carac[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

int	verif_min(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->bool_c = 0;
	g->bool_e = 0;
	g->bool_p = 0;
	while (g->m_cnt[i])
	{
		while (g->m_cnt[i][j++])
		{
			if (g->m_cnt[i][j] == 'C')
				g->bool_c = 1;
			if (g->m_cnt[i][j] == 'P')
				g->bool_p = 1;
			if (g->m_cnt[i][j] == 'E')
				g->bool_e = 1;
		}
		j = 0;
		i ++;
	}
	if (g->bool_c != 1 || g->bool_e != 1 || g->bool_p != 1)
		return (0);
	return (1);
}

void	free_error(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->m_hgt_line)
	{
		if (g->m_cnt[i])
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
	system("leaks so_long");
}

int	general2(t_game *g)
{
	if (!verif_min(g) || !verif_mob(g))
	{
		ft_printf("\033[0;31mError\033[0m\nElements are missing in the map file\n");
		free_error(g);
		exit(0);
	}
	if (!verif_content(g))
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("An unauthorized element is present in the map file\n");
		free_error(g);
		exit(0);
	}
	pathfinding(g);
	if (!pathfinding_verif(g))
	{
		ft_printf("\033[0;31mError\033[0m\nThe map isn't finishable\n");
		free_error(g);
		exit(0);
	}
	return (1);
}

int	verif_mob(t_game *g)
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
				return (1);
			j ++;
		}
		j = 0;
		i ++;
	}
	return (0);
}
