/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 12:28:49 by edurance         ###   ########.fr       */
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

void	*create_image(t_cub *cube)
{
	t_data	image;
	char	*dst;
	int		x;
	int		y;

	get_mapdata_display(cube);
	image.img = mlx_new_image(cube->mlx, cube->longest_line * cube->mapcub_size, cube->nb_lines * cube->mapcub_size);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	y = 0;
	while (y < cube->nb_lines * cube->mapcub_size)
	{
		x = 0;
		while (x < cube->longest_line * cube->mapcub_size)
		{
			dst = image.addr + (y * image.line_length + x
					* (image.bits_per_pixel / 8));
			if (cube->map[y / cube->mapcub_size][x / cube->mapcub_size] == '1')
				*(unsigned int *)dst = ft_color(255, 0, 0);
			else if (cube->map[y / cube->mapcub_size][x / cube->mapcub_size] == '0')
				*(unsigned int *)dst = ft_color(0, 255, 0);
			x++;
		}
		y++;
	}
	return (image.img);
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
		mlx_put_image_to_window(cube->mlx, cube->mlx_window, image, cube->map_x, cube->map_y);
		mlx_destroy_image(cube->mlx, image);
		printf("posx = %f posy = %f angX = %f angY = %f\n", cube->player->posX, cube->player->posY, cube->player->dirX, cube->player->dirY);
	}
	mlx_loop(cube->mlx);
	free(cube);
	return (0);
}
