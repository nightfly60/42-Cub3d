/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 11:18:48 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_cub *cube, char **av)
{
	create_map(cube, av[1]);
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "minimap");
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
	t_cub	*pacoub3d;
	void	*image;

	if (ac != 2)
		return (1);
	pacoub3d = malloc(sizeof(t_cub));
	if (!pacoub3d)
		return (0);
	init_game(pacoub3d, av);
	while (1)
	{
		image = create_image(pacoub3d);
		mlx_put_image_to_window(pacoub3d->mlx, pacoub3d->mlx_window, image, pacoub3d->map_x, pacoub3d->map_y);
		mlx_destroy_image(pacoub3d->mlx, image);
	}
	mlx_loop(pacoub3d->mlx);
	free(pacoub3d);
	return (0);
}
