/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:00:25 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/15 17:42:54 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_set(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		k;
	char	*r_str;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	k = 0;
	while (is_set(set, s1[start]))
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	while (is_set(set, s1[end]))
		end--;
	r_str = (malloc(sizeof(char) * (end - start + 2)));
	if (!r_str)
		return (NULL);
	while (start <= end)
		r_str[k++] = s1[start++];
	r_str[k] = '\0';
	return (r_str);
}
