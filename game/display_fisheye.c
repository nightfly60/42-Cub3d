/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fisheye.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:28:08 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 16:28:44 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_north(t_ray *ray, t_cub *cube, int x, t_data *image)
{
	float	d;
	int		tex_y;
	int		y;
	int		color;

	y = ray->draw_start;
	ray->text_x = (int)(ray->wall_x * (float)cube->textures->north->width);
	while (y < ray->draw_end)
	{
		d = y - SIZE_Y / 2 + ray->line_height / 2;
		tex_y = (int)(d * cube->textures->north->height / ray->line_height);
		color = get_pixel_color(cube->textures->north, ray->text_x, tex_y);
		put_pixel(image, x, y, color);
		y++;
	}
}

static void	display_south(t_ray *ray, t_cub *cube, int x, t_data *image)
{
	float	d;
	int		tex_y;
	int		y;
	int		color;

	y = ray->draw_start;
	ray->text_x = (int)(ray->wall_x * (float)cube->textures->south->width);
	while (y < ray->draw_end)
	{
		d = y - SIZE_Y / 2 + ray->line_height / 2;
		tex_y = (int)(d * cube->textures->south->height / ray->line_height);
		color = get_pixel_color(cube->textures->south, ray->text_x, tex_y);
		put_pixel(image, x, y, color);
		y++;
	}
}

static void	display_east(t_ray *ray, t_cub *cube, int x, t_data *image)
{
	float	d;
	int		tex_y;
	int		y;
	int		color;

	y = ray->draw_start;
	ray->text_x = (int)(ray->wall_x * (float)cube->textures->east->width);
	while (y < ray->draw_end)
	{
		d = y - SIZE_Y / 2 + ray->line_height / 2;
		tex_y = (int)(d * cube->textures->east->height / ray->line_height);
		color = get_pixel_color(cube->textures->east, ray->text_x, tex_y);
		put_pixel(image, x, y, color);
		y++;
	}
}

static void	display_west(t_ray *ray, t_cub *cube, int x, t_data *image)
{
	float	d;
	int		tex_y;
	int		y;
	int		color;

	y = ray->draw_start;
	ray->text_x = (int)(ray->wall_x * (float)cube->textures->west->width);
	while (y < ray->draw_end)
	{
		d = y - SIZE_Y / 2 + ray->line_height / 2;
		tex_y = (int)(d * cube->textures->west->height / ray->line_height);
		color = get_pixel_color(cube->textures->west, ray->text_x, tex_y);
		put_pixel(image, x, y, color);
		y++;
	}
}

void	display_fisheye(t_ray *ray, t_data *image, int x, t_cub *cube)
{
	ray->draw_start = (float)((-1 * ray->line_height) / 2 + SIZE_Y / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (float)(ray->line_height / 2 + SIZE_Y / 2);
	if (ray->draw_end >= SIZE_Y)
		ray->draw_end = SIZE_Y;
	if (!ray->side)
	{
		if (ray->ray_dir_x > 0)
			display_east(ray, cube, x, image);
		else
			display_west(ray, cube, x, image);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			display_south(ray, cube, x, image);
		else
			display_north(ray, cube, x, image);
	}
}
