/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:42:08 by sforesti          #+#    #+#             */
/*   Updated: 2023/01/24 10:33:19 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_nl(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*get_buffer(int fd, char *buf_fd)
{
	char	*buf_temp;
	int		i;

	i = 1;
	if (!buf_fd)
		buf_fd = ft_calloc(1, 1);
	buf_temp = 0;
	while (find_nl(buf_fd) == -1 && i != 0)
	{
		buf_temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		i = read(fd, buf_temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf_fd);
			buf_fd = NULL;
			free(buf_temp);
			buf_temp = NULL;
			return (buf_fd);
		}
		buf_temp[i] = '\0';
		buf_fd = ft_strjoin(buf_fd, buf_temp);
	}
	return (buf_fd);
}

char	*fill_line(char *buf_fd)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = -1;
	if (!buf_fd)
		return (NULL);
	while (buf_fd[i] != '\n' && buf_fd[i])
		i ++;
	ret = ft_calloc(sizeof(char), i + 2);
	while (++j < i + 1)
		ret[j] = buf_fd[j];
	ret[j] = '\0';
	if (!ret[0])
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*reset_buf(char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	if (!buf)
		return (NULL);
	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i ++;
	tmp = ft_calloc(sizeof(char), ft_strlen(buf) - i + 2);
	while (buf[++i - 1])
		tmp[j++] = buf[i];
	tmp[j] = '\0';
	free(buf);
	buf = NULL;
	if (!tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	if (fd == -1)
	{
		if (buf)
		{	
			free(buf);
			buf = NULL;
		}
		return (NULL);
	}
	buf = get_buffer(fd, buf);
	ret = fill_line(buf);
	buf = reset_buf(buf);
	return (ret);
}
