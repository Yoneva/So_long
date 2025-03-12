/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:49:19 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:31:53 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "../MLX/MLX42/include/MLX42/MLX42.h"

# define PIXELS 64

typedef struct a_map_chars {
	int			collectible;
	int			exit;
	int			player;
	int			player_x;
	int			player_y;
	int			exit_y;
	int			exit_x;
	int			map_height;
	mlx_t		*mlx;
	char		**map;
	int			fd;
	mlx_image_t	*player_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*path_img;
	mlx_image_t	*exit_img;
}	t_maps_chars;

int			main(int ac, char **av);
void		eaten_collectibles(t_maps_chars *game);
char		**parsing(int fd, t_maps_chars *game);
mlx_image_t	*texturize(char *path, mlx_t *mlx);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_realloc(void *str, size_t newsize);
void		flood_fill(char **map, t_maps_chars side);
bool		find_player(char **map, t_maps_chars *player);
char		**copy_arr(char **arr);
bool		rectangle_checker(char **arr);
bool		all_1(char *line);
void		error_message(char **arr, int n);
void		valid_map(char **map, t_maps_chars *side);
void		put_image(mlx_t *mlx, char *arr, t_maps_chars *game, int j);
void		move_player(mlx_t *mlx, t_maps_chars info);

#endif