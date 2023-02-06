/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:21:29 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/06 17:21:51 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *g)
{
	free_all(g);
	exit(0);
}

int	verif_map_name(char **argv)
{
	if (argv[1][(ft_strlen(argv[1]) - 3)] != 'b'
		|| argv[1][(ft_strlen(argv[1]) - 2)] != 'e'
			|| argv[1][(ft_strlen(argv[1]) - 1)] != 'r')
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("Extension '.ber' is required for map file\n");
		return (1);
	}
	return (0);
}

void	get_map2(t_game *g, int i, char *line, char *map_temp)
{
	g->m_hgt_line = i;
	g->m_cnt = ft_split(map_temp, '\n');
	g->m_hgt = SIZE_TILES * i;
	g->m_wdt = ft_strlen(g->m_cnt[0]) * SIZE_TILES;
	if (line)
		free(line);
	if (map_temp)
		free(map_temp);
}
