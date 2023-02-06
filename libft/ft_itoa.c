/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:01:37 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 11:59:10 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	size(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i ++;
	}
	while (n > 9)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	n_bis;

	n_bis = (long)n;
	len = size(n_bis);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n_bis < 0)
	{
		n_bis = -n_bis;
		str[0] = '-';
	}
	str[len--] = '\0';
	while (n_bis > 9)
	{
		str[len--] = (n_bis % 10) + 48;
		n_bis /= 10;
	}
	str[len] = n_bis + 48;
	return (str);
}
