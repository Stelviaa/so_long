/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:57:45 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 11:19:34 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_bis;

	i = -1;
	s_bis = (char *)s;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (&s_bis[i]);
	}
	if ((char)c == '\0')
		return (&s_bis[i]);
	return (NULL);
}
