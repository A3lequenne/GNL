/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllequen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:54:09 by cllequen          #+#    #+#             */
/*   Updated: 2022/02/22 16:54:20 by cllequen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*trans;

	trans = (unsigned char *)s;
	while (size > 0)
	{
		*trans++ = '\0';
		size--;
	}
}

void	*ft_malloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != c && *tmp != 0)
		tmp++;
	if (*tmp == c)
		return (tmp);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;
	size_t	len_1;
	size_t	len_2;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char *) * (len_1 + len_2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (len_1-- > 0)
		new_str[i++] = s1[j++];
	j = 0;
	while (len_2-- > 0)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
