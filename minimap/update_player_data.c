/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:40:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/14 16:03:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clc_step_side(t_ply *ply, t_ray *ray)
{
	if (ray->rayDirX >= 0)
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0f - ply->posX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = -1;
		ray->sideDistX = (ply->posX - ray->mapX) * ray->deltaDistX;
	}
	if (ray->rayDirY >= 0)
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0f - ply->posY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = -1;
		ray->sideDistY = (ply->posY - ray->mapY) * ray->deltaDistY;
	}
}

static void	init_dda_datas(t_ply *ply, t_ray *ray)
{
	ray->mapX = (int)ply->posX;
	ray->mapY = (int)ply->posY;
	if (ray->rayDirX)
		ray->deltaDistX = fabsf(1 / ray->rayDirX);
	else
		ray->deltaDistX = FLT_MAX;
	if (ray->rayDirY)
		ray->deltaDistY = fabsf(1 / ray->rayDirY);
	else
		ray->deltaDistY = FLT_MAX;
	clc_step_side(ply, ray);
}

static void	display_ray(t_cub *cube, t_data *image, t_ray *ray)
{
	float	dist;
	float	endLine[2];
	float	startLine[2];

	if (!ray->side)
		dist = ray->sideDistX - ray->deltaDistX;
	else
		dist = ray->sideDistY - ray->deltaDistY;
	endLine[0] = (cube->player->posX + dist * ray->rayDirX) * cube->mapcub_size;
	endLine[1] = (cube->player->posY + dist * ray->rayDirY) * cube->mapcub_size;
	startLine[0] = cube->player->posX * cube->mapcub_size;
	startLine[1] = cube->player->posY * cube->mapcub_size;
	ft_drawline(startLine, endLine, image);
}

static void	next_wall_dist(t_cub *cube, t_data *image, t_ray *ray)
{
	int	wall;

	init_dda_datas(cube->player, ray);
	wall = 0;
	while (!wall)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX = ray->sideDistX + ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (cube->map[ray->mapY][ray->mapX] == '1')
			wall = 1;
	}
	display_ray(cube, image, ray);
}

void	launch_rays(t_cub *cube, t_data *image)
{
	int		i;
	t_ray	ray;

	i = 0;
	ray.planeX = cube->player->dirY * -1 * 0.66;
	ray.planeY = cube->player->dirX * 0.66;
	while (i < SIZE_X)
	{
		ray.cameraX = 2 * i / (float)SIZE_X - 1.0f;
		ray.rayDirX = cube->player->dirX + ray.planeX * ray.cameraX;
		ray.rayDirY = cube->player->dirY + ray.planeY * ray.cameraX;
		next_wall_dist(cube, image, &ray);
		i++;
	}
}
