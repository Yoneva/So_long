/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:11:32 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:14:11 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*malloc_str(char *src)
{
	int		len;
	char	*tmp;

	len = ft_strlen(src);
	tmp = malloc(len + 1);
	ft_memcpy(tmp, src, len + 1);
	return (tmp);
}

char	**copy_arr(char **arr)
{
	int		i;
	int		j;
	int		size;
	char	**tmp;

	i = 0;
	j = 0;
	size = 1;
	tmp = malloc(size * sizeof(char *));
	while (arr[i])
	{
		tmp[i] = malloc_str(arr[i]);
		size++;
		tmp = ft_realloc(tmp, size * sizeof(char *));
		i++;
	}
	tmp[size - 1] = NULL;
	return (tmp);
}
