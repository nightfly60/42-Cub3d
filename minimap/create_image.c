/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:41:04 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/14 10:47:21 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_background(t_cub *cube, t_data *image)
{
	int		x;
	int		y;
	char	*dst;
	char	c;

	y = 0;
	while (y < cube->nb_lines * cube->mapcub_size)
	{
		x = 0;
		while (x < cube->longest_line * cube->mapcub_size)
		{
			dst = image->addr + (y * image->line_length + x
					* (image->bits_per_pixel / 8));
			c = cube->map[y / cube->mapcub_size][x / cube->mapcub_size];
			if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
				*(unsigned int *)dst = ft_color(0, 120, 0);
			else
				*(unsigned int *)dst = ft_color(255, 0, 0);
			x++;
		}
		y++;
	}
}

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	map_player(t_cub *cube, t_data *image, int ray)
{
	int	x;
	int	y;
	int	x_origin;
	int	y_origin;
	int	dist;

	x_origin = (int)(cube->player->posX * cube->mapcub_size);
	y_origin = (int)(cube->player->posY * cube->mapcub_size);
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

int	display_minimap(t_cub *cube)
{
	t_data	image;

	get_mapdata_display(cube);
	image.img = mlx_new_image(cube->mlx, cube->longest_line * cube->mapcub_size,
			cube->nb_lines * cube->mapcub_size);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	map_background(cube, &image);
	map_player(cube, &image, 10);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, image.img, cube->map_x,
		cube->map_y);
	mlx_destroy_image(cube->mlx, image.img);
	next_wall_dist(cube);
	// printf("posx = %f posy = %f angX = %f angY = %f\n", cube->player->posX,
	// 	cube->player->posY, cube->player->dirX, cube->player->dirY);
	return (1);
}
