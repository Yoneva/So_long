/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:31:07 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:42:33 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*texturize(char *path, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		return (NULL);
	mlx_delete_texture(texture);
	return (img);
}

void	texturizing(t_maps_chars *game)
{
	game->wall_img = texturize("IMG/Trap.png", game->mlx);
	game->player_img = texturize("IMG/Koala.png", game->mlx);
	game->collect_img = texturize("IMG/Star.png", game->mlx);
	game->path_img = texturize("IMG/Path.png", game->mlx);
}

void	put_image(mlx_t *mlx, char *arr, t_maps_chars *game, int j)
{
	int	i;

	i = 0;
	if (j == 0)
		texturizing(game);
	while (arr[i])
	{
		if (arr[i] == '1')
			mlx_image_to_window(mlx, game->wall_img,
				i * PIXELS, j * PIXELS);
		else if (arr[i] == 'P')
		{
			mlx_image_to_window(mlx, game->path_img,
				i * PIXELS, j * PIXELS);
			mlx_image_to_window(mlx, game->player_img,
				i * PIXELS, j * PIXELS);
		}
		else if (arr[i] == 'C')
			mlx_image_to_window(mlx, game->collect_img,
				i * PIXELS, j * PIXELS);
		if (arr[i] == '0' || arr[i] == 'E')
			mlx_image_to_window(mlx, game->path_img,
				i * PIXELS, j * PIXELS);
		i++;
	}
}
