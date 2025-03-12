/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:18:06 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:46:55 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char **arr, int n)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	if (n == 1)
	{
		write(1, "Error!\n", 7);
		exit (1);
	}
}

bool	all_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	rectangle_checker(char **arr)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(arr[0]);
	while (arr[i])
	{
		if (ft_strlen(arr[i]) != len)
			error_message(arr, 1);
		i++;
	}
	return (true);
}
