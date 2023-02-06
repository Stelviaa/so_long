/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:15 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 13:28:17 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_bis;

	s_bis = (char *)s;
	i = -1;
	while (++i < n)
	{
		if (s_bis[i] == (char)c)
			return (&s_bis[i]);
	}
	return (NULL);
}
