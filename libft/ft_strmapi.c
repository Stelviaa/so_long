/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:50:33 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 14:59:20 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r_str;

	if (!s)
		return (NULL);
	i = -1;
	r_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r_str)
		return (NULL);
	while (s[++i])
		r_str[i] = f(i, s[i]);
	r_str[i] = '\0';
	return (r_str);
}
