/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:03:05 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/10 19:06:04 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*s_return;
	int		i;

	s_return = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!s_return)
		return (NULL);
	i = 0;
	while (src[i])
	{
		s_return[i] = src[i];
		i++;
	}
	s_return[i] = '\0';
	return (s_return);
}
