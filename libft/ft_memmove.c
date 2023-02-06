/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:49:37 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/10 15:59:32 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dest_bis;
	char	*src_bis;

	if (!dest && !src)
		return (dest);
	dest_bis = (char *)dest;
	src_bis = (char *)src;
	i = -1;
	if (dest > src)
		while (len--)
			dest_bis[len] = src_bis[len];
	else
		while (++i < len)
			dest_bis[i] = src_bis[i];
	return (dest);
}
