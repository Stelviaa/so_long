/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:14:35 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/23 15:14:10 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	r_str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		r_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r_str[i] = s2[j++];
		i ++;
	}
	r_str[i] = '\0';
	free(s1);
	free(s2);
	return (r_str);
}
