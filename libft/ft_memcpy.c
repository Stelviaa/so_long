/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:15:58 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/10 13:14:19 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_bis;
	char	*src_bis;

	if (!dest && !src)
		return (dest);
	dest_bis = (char *)dest;
	src_bis = (char *)src;
	i = -1;
	while (++i < n)
		dest_bis[i] = src_bis[i];
	return (dest);
}
