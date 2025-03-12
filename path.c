/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:37:20 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:44:00 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	find_player(char **map, t_maps_chars *player)
{
	while (map[player->player_x])
	{
		player->player_y = 0;
		while (map[player->player_x][player->player_y])
		{
			if (map[player->player_x][player->player_y] == 'P')
				return (true);
			player->player_y++;
		}
		player->player_x++;
	}
	return (false);
}

void	flood_fill(char **map, t_maps_chars side)
{
	t_maps_chars	down;
	t_maps_chars	up;
	t_maps_chars	right;
	t_maps_chars	left;
	int				width;

	width = ft_strlen(map[0]);
	if (map[side.player_x][side.player_y] == '1')
		return ;
	map[side.player_x][side.player_y] = '1';
	down.player_x = side.player_x + 1;
	down.player_y = side.player_y;
	up.player_x = side.player_x - 1;
	up.player_y = side.player_y;
	right.player_x = side.player_x;
	right.player_y = side.player_y + 1;
	left.player_x = side.player_x;
	left.player_y = side.player_y - 1;
	flood_fill(map, down);
	flood_fill(map, up);
	flood_fill(map, right);
	flood_fill(map, left);
}

void	valid_map(char **map, t_maps_chars *side)
{
	int		i;
	int		j;
	char	**tmp;

	side->player_x = 0;
	side->player_y = 0;
	i = 0;
	j = 0;
	tmp = copy_arr(map);
	find_player(map, side);
	flood_fill(tmp, *side);
	while (tmp[j])
	{
		i = 0;
		while (tmp[j][i])
		{
			if (tmp[j][i] != '0' && tmp[j][i] != '1')
				error_message(map, 1);
			i++;
		}
		j++;
	}
	error_message(tmp, 0);
	return ;
}
