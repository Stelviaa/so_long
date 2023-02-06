/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:37 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 11:55:25 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return (ft_strlen(src));
	while (++i != n - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
