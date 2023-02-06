/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:45 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/24 10:53:02 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_out(va_list av1)
{
	char	c;

	c = va_arg(av1, int);
	write(1, &c, 1);
	return (1);
}

void	ft_conv_hexa(unsigned long long p, char *hexa)
{
	if (p > 15)
	{
		ft_conv_hexa(p / 16, hexa);
		write(1, &hexa[p % 16], 1);
	}
	else
		write(1, &hexa[p], 1);
}

int	p_out(va_list av1)
{
	unsigned long long	p;
	int					i;

	p = va_arg(av1, unsigned long long);
	write(1, "0x", 2);
	ft_conv_hexa(p, "0123456789abcdef");
	i = 0;
	if (!p)
		return (3);
	while (p)
	{
		p /= 16;
		i ++;
	}
	return (i + 2);
}

int	d_i_out(va_list av1)
{
	int	i;
	int	nb;
	int	negative;

	nb = va_arg(av1, int);
	negative = 0;
	if (nb < 0)
		negative = 1;
	ft_putnbr(nb);
	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i ++;
	}
	if (negative)
		return (i + 1);
	return (i);
}
