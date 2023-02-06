/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:39 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/10 17:27:27 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!(haystack) && len == 0)
		return (NULL);
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[++i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
