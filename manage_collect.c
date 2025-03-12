/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:42:41 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:48:08 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find(char **map, char c, t_maps_chars *game)
{
	game->exit_x = 0;
	while (map[game->exit_x])
	{
		game->exit_y = 0;
		while (map[game->exit_x][game->exit_y])
		{
			if (map[game->exit_x][game->exit_y] == c)
				return ;
			game->exit_y++;
		}
		game->exit_x++;
	}
}

void	eaten_collectibles(t_maps_chars *game)
{
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->path_img, 
			game->player_y * PIXELS, game->player_x * PIXELS);
		game->map[game->player_x][game->player_y] = '.';
		game->collectible--;
		mlx_image_to_window(game->mlx, game->player_img, 
			game->player_y * PIXELS, game->player_x * PIXELS);
	}
	if (game->collectible == 0)
	{
		game->exit_img = texturize("IMG/Exit.png", game->mlx);
		find(game->map, 'E', game);
		mlx_image_to_window(game->mlx, game->exit_img, 
			game->exit_y * PIXELS, game->exit_x * PIXELS);
	}
	if (game->map[game->player_x][game->player_y] 
		== 'E' && game->collectible == 0)
		mlx_close_window(game->mlx);
}
