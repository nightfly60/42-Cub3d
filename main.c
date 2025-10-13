/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 12:46:45 by aabouyaz         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_cub	*cube;
	void	*image;

	if (ac != 2)
		return (1);
	cube = malloc(sizeof(t_cub));
	if (!cube)
		return (0);
	init_game(cube, av);
	while (1)
	{
		image = create_image(cube);
		mlx_put_image_to_window(cube->mlx, cube->mlx_window, image, cube->map_x,
			cube->map_y);
		mlx_destroy_image(cube->mlx, image);
		printf("posx = %f posy = %f angX = %f angY = %f\n", cube->player->posX, cube->player->posY, cube->player->dirX, cube->player->dirY);
	}
	mlx_loop(cube->mlx);
	free(cube);
	return (0);
}
