/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:34:10 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:24 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_bis;
	char	*s2_bis;

	i = -1;
	s1_bis = (char *)s1;
	s2_bis = (char *)s2;
	while (++i < n)
	{
		if (s1_bis[i] != s2_bis[i])
			return ((unsigned char)s1_bis[i] - (unsigned char)s2_bis[i]);
	}
	return (0);
}
