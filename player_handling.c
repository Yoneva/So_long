/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:41:13 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 21:47:05 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*move(int y, int x, t_maps_chars *spot)
{
	mlx_delete_image(spot->mlx, spot->player_img);
	spot->player_img = texturize("IMG/Koala.png", spot->mlx);
	mlx_image_to_window(spot->mlx, spot->player_img, y * PIXELS, x * PIXELS);
	return (spot->player_img);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_maps_chars		*spot;
	static mlx_image_t	*player;

	spot = (t_maps_chars *)param;
	if (!player)
		mlx_image_to_window(spot->mlx, spot->player_img,
			(spot->player_x * PIXELS), (spot->player_y * PIXELS));
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W 
			&& spot->map[spot->player_x - 1][spot->player_y] != '1')
			player = move(spot->player_y, spot->player_x -= 1, spot);
		else if (keydata.key == MLX_KEY_S 
			&& spot->map[spot->player_x + 1][spot->player_y] != '1')
			player = move(spot->player_y, spot->player_x += 1, spot);
		else if (keydata.key == MLX_KEY_A 
			&& spot->map[spot->player_x][spot->player_y - 1] != '1')
			player = move(spot->player_y -= 1, spot->player_x, spot);
		else if (keydata.key == MLX_KEY_D 
			&& spot->map[spot->player_x][spot->player_y + 1] != '1')
			player = move(spot->player_y += 1, spot->player_x, spot);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(spot->mlx);
	}
	eaten_collectibles(spot);
}

void	move_player(mlx_t *mlx, t_maps_chars info)
{
	mlx_key_hook(mlx, key_handler, &info);
}
