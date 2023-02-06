/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:27:50 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/23 15:14:58 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	pt = malloc(nmemb * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
