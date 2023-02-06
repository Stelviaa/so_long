/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:44:52 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/24 10:50:07 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exception(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	char	nb_p;
	int		i;

	i = 0;
	if (ft_exception(nb))
		return ;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		nb_p = (nb % 10) + 48;
		ft_putnbr(nb / 10);
		write(1, &nb_p, 1);
	}
	else
	{
		nb_p = nb + 48;
		write(1, &nb_p, 1);
	}
}
