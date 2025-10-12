/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/12 17:23:06 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_map(t_cub *cube, char *mapfile)
{
	int		fd;
	char	*line;
	int		i;

	line = "";
	i = 0;
	cube->map = malloc(sizeof(char *) * 50); // HARDCODE
	if (!cube->map)
		return ;
	cube->longest_line = 0;
	fd = open(mapfile, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		cube->map[i] = line;
		if (cube->longest_line < (int)ft_strlen(line))
			cube->longest_line = (int)ft_strlen(line);
		i++;
	}
	close(fd);
}

static void	init_game(t_cub *cube, char **av)
{
	create_map(cube, av[1]);
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "minimap");
}

static int	ft_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	*create_image(t_cub *cube, int size_x, int size_y)
{
	t_data	image;
	char	*dst;
	int		x;
	int		y;

	image.img = mlx_new_image(cube->mlx, size_x * 105, size_y * 105);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	y = 0;
	while (y < size_y * 105)
	{
		x = 0;
		while (x < size_x * 105)
		{
			dst = image.addr + (y * image.line_length + x
					* (image.bits_per_pixel / 8));
			if (cube->map[y / 105][x / 105] == '1')
				*(unsigned int *)dst = ft_color(255, 0, 0);
			else if (cube->map[y / 105][x / 105] == '\n')
				*(unsigned int *)dst = ft_color(255, 255, 255);
			else
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
		image = create_image(pacoub3d, pacoub3d->longest_line, 5);
		mlx_put_image_to_window(pacoub3d->mlx, pacoub3d->mlx_window, image, 0, 0);
		mlx_destroy_image(pacoub3d->mlx, image);
	}
	mlx_loop(pacoub3d->mlx);
	free(pacoub3d);
	return (0);
}
