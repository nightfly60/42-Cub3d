/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/16 11:12:57 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_cub *cube, char **av)
{
	cube->player = NULL;
	cube->map = NULL;
	cube->mlx = NULL;
	cube->mlx_window_minimap = NULL;
	cube->mlx_window_game = NULL;
	cube->img_minimap = NULL;
	cube->img_game = NULL;
	cube->ceiling_color = ft_color(0, 255, 255);
	cube->floor_color = ft_color(255, 192, 203);
	cube->minimap_sizex = SIZE_X * 0.25;
	cube->minimap_sizey = SIZE_Y * 0.25;
	cube->fps = ft_itoa(0);
	create_map(cube, av[1]);
	cube->mlx = mlx_init();
	cube->mlx_window_minimap = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y,
			"minimap");
	cube->mlx_window_game = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "game");
	cube->player = malloc(sizeof(t_ply));
	if (!cube->player)
		exit_game(cube);
	init_player_data(cube);
	mlx_hook(cube->mlx_window_game, KeyPress, KeyPressMask, key_hooks, cube);
	mlx_hook(cube->mlx_window_game, 17, 0, close_game, (void *)cube);
}

int	main(int ac, char **av)
{
	t_cub	*cube;

	if (ac != 2)
		return (1);
	cube = malloc(sizeof(t_cub));
	if (!cube)
		return (0);
	init_game(cube, av);
	mlx_loop_hook(cube->mlx, display_game, cube);
	mlx_loop(cube->mlx);
	free(cube);
	return (0);
}
