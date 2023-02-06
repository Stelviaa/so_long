/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:34:43 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/15 18:08:31 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dest && size == 0)
		return (0);
	while (dest[i] && i < size)
		i++;
	while (src[j] && (j + i) < size - 1 && size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}
