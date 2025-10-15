/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:41:04 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/15 15:11:35 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Dessine les (mapcub_size) pixels de chaque ligne a la bonne couleur*/
static void	draw_case(t_cub *cube, t_data *image, int y, int x)
{
	char	*dst;
	char	c;
	int		z;

	z = 0;
	c = cube->map[y / cube->mapcub_size][x];
	while (z < cube->mapcub_size)
	{
		dst = image->addr + (y * image->line_length + (z + x
					* cube->mapcub_size) * (image->bits_per_pixel / 8));
		if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
			*(unsigned int *)dst = ft_color(0, 120, 0);
		else
			*(unsigned int *)dst = ft_color(255, 0, 0);
		z++;
	}
}

/*Dessine dans l'image la map en 2D*/
static void	map_background(t_cub *cube, t_data *image)
{
	int		x;
	int		y;

	y = 0;
	while (y < cube->nb_lines * cube->mapcub_size)
	{
		x = 0;
		while (cube->map[y / cube->mapcub_size][x])
		{
			draw_case(cube, image, y, x);
			x++;
		}
		y++;
	}
}

/*Dessine le player sur la map en 2D*/
static void	map_player(t_cub *cube, t_data *image, int ray)
{
	int	x;
	int	y;
	int	x_origin;
	int	y_origin;
	int	dist;

	x_origin = (int)(cube->player->pos_x * cube->mapcub_size);
	y_origin = (int)(cube->player->pos_y * cube->mapcub_size);
	x = (x_origin - ray);
	while (x <= x_origin + ray)
	{
		y = y_origin - ray;
		while (y <= y_origin + ray)
		{
			dist = (x - x_origin) * (x - x_origin) + (y - y_origin) * (y
					- y_origin);
			if (dist < ray * ray)
				put_pixel(image, x, y, ft_color(255, 255, 255));
			y++;
		}
		x++;
	}
}

/*Fonction qui affiche une frame de la minimap (appelee dans un hook_loop)*/
int	display_minimap(t_cub *cube)
{
	t_data	image;

	image.img = NULL;
	cube->img = image.img;
	get_mapdata_display(cube);
	image.img = mlx_new_image(cube->mlx, cube->longest_line * cube->mapcub_size,
			cube->nb_lines * cube->mapcub_size);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	map_background(cube, &image);
	map_player(cube, &image, 10);
	launch_rays(cube, &image);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, image.img, cube->map_x,
		cube->map_y);
	mlx_destroy_image(cube->mlx, image.img);
	return (1);
}
