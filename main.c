/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:34:57 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/12 23:49:06 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] != '.' || str[len - 2] != 'b' 
		|| str[len - 1] != 'e' || str[len] != 'r')
	{
		write(1, "file is not a BER encoded file\n", 31);
		exit (1);
	}
}

void	start_game(t_maps_chars	*game)
{
	int	i;

	i = 0;
	game->mlx = mlx_init((ft_strlen(game->map[0]) * PIXELS),
			(game->map_height * PIXELS), "so_long", true);
	while (game->map[i])
	{
		put_image(game->mlx, game->map[i], game, i);
		i++;
	}
	move_player(game->mlx, *game);
	mlx_loop(game->mlx);
	error_message(game->map, 0);
	mlx_terminate(game->mlx);
}

// void leaks(void)
// {
// 	system("leaks so_long");
// }
// atexit(leaks);
int	main(int ac, char **av)
{
	t_maps_chars	game;

	if (ac != 2)
	{
		write(1, "Arguments!!'-'\n", 15);
		return (1);
	}
	game.collectible = 0;
	game.exit = 0;
	game.player = 0;
	check_input(av[1]);
	game.fd = open(av[1], O_RDONLY);
	if (game.fd == -1)
	{
		perror("Couldn't open the file '-'");
		return (1);
	}
	game.map = parsing(game.fd, &game);
	start_game(&game);
	close (game.fd);
}
