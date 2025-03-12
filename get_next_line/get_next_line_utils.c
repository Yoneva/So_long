/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/17 18:30:28 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srcc;
	char	*dstt;
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	srcc = (char *)src;
	dstt = (char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	s = malloc(sizeof(char) * size);
	if (!s)
		return (0);
	s[size - 1] = 0;
	ft_memcpy(s, s1, s1_len);
	ft_memcpy(s + s1_len, s2, s2_len);
	return (s);
}
