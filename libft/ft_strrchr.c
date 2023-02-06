/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:20 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 11:20:45 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_bis;
	size_t	len;

	i = -1;
	len = ft_strlen(s) - 1;
	s_bis = (char *)s;
	while (s[++i])
	{
		if (s[len] == (char)c)
			return (&s_bis[len]);
		len--;
	}
	if ((char)c == '\0')
		return (&s_bis[ft_strlen(s)]);
	return (NULL);
}
