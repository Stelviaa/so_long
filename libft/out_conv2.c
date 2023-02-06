/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_conv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:24:44 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/24 10:53:22 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	u_out(va_list av1)
{
	int				i;
	unsigned int	nb;
	int				negative;

	nb = va_arg(av1, unsigned int);
	negative = 0;
	putnbr_u(nb);
	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i ++;
	}
	return (i);
}

int	s_out(va_list av1)
{
	char	*s_ret;
	int		i;

	i = -1;
	s_ret = va_arg(av1, char *);
	if (!s_ret)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s_ret[++i])
		write(1, &s_ret[i], 1);
	return (i);
}

int	x_maj_out(va_list av1)
{
	unsigned int	p;
	int				i;

	p = va_arg(av1, unsigned int);
	ft_conv_hexa(p, "0123456789ABCDEF");
	if (!p)
		return (1);
	i = 0;
	while (p)
	{
		p /= 16;
		i ++;
	}
	return (i);
}

int	x_out(va_list av1)
{
	unsigned int	p;
	int				i;

	p = va_arg(av1, unsigned int);
	ft_conv_hexa(p, "0123456789abcdef");
	i = 0;
	if (!p)
		return (1);
	while (p)
	{
		p /= 16;
		i ++;
	}
	return (i);
}

int	percent_out(void)
{
	write(1, "%", 1);
	return (1);
}
