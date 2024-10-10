/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllequen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:03:12 by cllequen          #+#    #+#             */
/*   Updated: 2022/02/22 17:20:30 by cllequen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *rest, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(rest, buf);
	free(rest);
	return (tmp);
}

char	*read_line(int fd, char *res)
{
	char	*buf;
	int		i;

	if (!res)
		res = ft_malloc(1, 1);
	buf = ft_malloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		res = ft_free(res, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (res);
}

char	*take_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	line = ft_malloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n' && buf[i])
		line[i++] = '\n';
	return (line);
}

char	*take_next(char *rest)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	next_line = ft_malloc((ft_strlen(rest) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rest[i])
		next_line[j++] = rest[i++];
	free(rest);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stat_str;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_str = read_line(fd, stat_str);
	if (!stat_str)
		return (NULL);
	line = take_line(stat_str);
	stat_str = take_next(stat_str);
	return (line);
}
