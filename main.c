/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 14:52:53 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_cub *cube, char **av)
{
	create_map(cube, av[1]);
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "minimap");
	cube->player = malloc(sizeof(t_ply));
	init_player_data(cube);
	mlx_hook(cube->mlx_window, KeyPress, KeyPressMask, key_hooks, cube);
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
	mlx_loop_hook(cube->mlx, display_minimap, cube);
	mlx_loop(cube->mlx);
	free(cube);
	return (0);
}
