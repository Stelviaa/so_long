/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:26:41 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/24 10:51:53 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	r_exit(char c, va_list av1)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = c_out(av1);
	else if (c == 's')
		i = s_out(av1);
	else if (c == 'p')
		i = p_out(av1);
	else if (c == 'd' || c == 'i')
		i = d_i_out(av1);
	else if (c == 'X')
		i = x_maj_out(av1);
	else if (c == 'x')
		i = x_out(av1);
	else if (c == 'u')
		i = u_out(av1);
	else if (c == '%')
		i = percent_out();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	av1;
	int		i;
	int		j;

	i = -1;
	j = 0;
	va_start(av1, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i ++;
			j += r_exit(format[i], av1);
		}
		else
		{
			write(1, &format[i], 1);
			j ++;
		}
	}
	va_end(av1);
	return (j);
}
