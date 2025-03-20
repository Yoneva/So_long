/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:10:37 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/17 20:37:17 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_letters(char **line, t_maps_chars *game, int i, int j)
{
	while (line[j])
	{
		i = 0;
		while (line[j][i])
		{
			if (line[j][i] == 'P')
				game->player += 1;
			else if (line[j][i] == 'C')
				game->collectible += 1;
			else if (line[j][i] == 'E')
				game->exit += 1;
			else if (line[j][i] == '1' || line[j][i] == '0' )
			{
				i++;
				continue ;
			}
			else
				error_message(line, 1);
			i++;
		}
		j++;
	}
	if (game->player != 1 || game->exit != 1 || game->collectible < 1)
		error_message(line, 1);
	return ;
}

void	if_walls(char **arr, int size)
{
	int	i;
	int	len;

	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (i == 0 && (all_1(arr[i]) == false))
			error_message(arr, 1);
		else if (i == (size - 2) && (all_1(arr[i]) == false))
			error_message(arr, 1);
		else
		{
			if (arr[i][0] != '1' || arr[i][len - 1] != '1')
				error_message(arr, 1);
		}
		i++;
	}
	return ;
}

void	check_error(char **arr, int size, t_maps_chars *game)
{
	if_walls(arr, size);
	check_letters(arr, game, 0, 0);
	rectangle_checker(arr);
	valid_map(arr, game);
}

char	**parsing(int fd, t_maps_chars *game)
{
	int		i;
	int		len;
	int		size;
	char	**arr;

	i = 0;
	size = 1;
	arr = malloc(size * sizeof(char *));
	while (1)
	{
		arr[i] = get_next_line(fd);
		if (!arr[i])
			break ;
		len = ft_strlen(arr[i]);
		if (arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		size += 1;
		arr = ft_realloc(arr, (size * sizeof(char *)));
		i++;
	}
	max_window(len, i, arr);
	arr[size] = NULL;
	game->map_height = size - 1;
	check_error(arr, size, game);
	return (arr);
}
