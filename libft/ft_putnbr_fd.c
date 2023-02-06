/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:26:38 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 16:11:43 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_exception(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nb_p;
	int		i;

	i = 0;
	if (ft_exception(n, fd))
		return ;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		nb_p = (n % 10) + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &nb_p, 1);
	}
	else
	{
		nb_p = n + 48;
		write(fd, &nb_p, 1);
	}
}
