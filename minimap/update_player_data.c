/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:40:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/15 15:16:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Calcule StepX/StepY et sideDistX/sideDistY*/
static void	calculate_step_side(t_ply *ply, t_ray *ray)
{
	if (ray->ray_dir_x >= 0)
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0f - ply->pos_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = -1;
		ray->sidedist_x = (ply->pos_x - ray->map_x) * ray->deltadist_x;
	}
	if (ray->ray_dir_y >= 0)
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0f - ply->pos_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->sidedist_y = (ply->pos_y - ray->map_y) * ray->deltadist_y;
	}
}

/*Initialise les variables necessaires au DDA:
	- mapX/mapY
	- rayDirX/rayDirY
	- sideDistX/sideDistY
	- deltaDistX/deltaDistY
	- stepX/stepY
*/
static void	init_dda_datas(t_ply *ply, t_ray *ray)
{
	ray->map_x = (int)ply->pos_x;
	ray->map_y = (int)ply->pos_y;
	if (ray->ray_dir_x)
		ray->deltadist_x = fabsf(1 / ray->ray_dir_x);
	else
		ray->deltadist_x = FLT_MAX;
	if (ray->ray_dir_y)
		ray->deltadist_y = fabsf(1 / ray->ray_dir_y);
	else
		ray->deltadist_y = FLT_MAX;
	calculate_step_side(ply, ray);
}

/*Affiche un rayon sur la minimap*/
static void	display_ray(t_cub *cube, t_data *image, t_ray *ray)
{
	float	dist;
	float	end_line[2];
	float	start_line[2];

	if (!ray->side)
		dist = ray->sidedist_x - ray->deltadist_x;
	else
		dist = ray->sidedist_y - ray->deltadist_y;
	end_line[0] = (cube->player->pos_x + dist * ray->ray_dir_x)
		* cube->mapcub_size;
	end_line[1] = (cube->player->pos_y + dist * ray->ray_dir_y)
		* cube->mapcub_size;
	start_line[0] = cube->player->pos_x * cube->mapcub_size;
	start_line[1] = cube->player->pos_y * cube->mapcub_size;
	ft_drawline(start_line, end_line, image);
}

/*Fonction qui applique le DDA et donc la distance entre le player
	et le premier mur dans la direction du rayon*/
static void	next_wall_dist(t_cub *cube, t_data *image, t_ray *ray)
{
	int	wall;

	init_dda_datas(cube->player, ray);
	wall = 0;
	while (!wall)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x = ray->sidedist_x + ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cube->map[ray->map_y][ray->map_x] == '1')
			wall = 1;
	}
	display_ray(cube, image, ray);
}

/*Envoie tous les rayons de la FOV du joueur*/
void	launch_rays(t_cub *cube, t_data *image)
{
	int		i;
	t_ray	ray;

	i = 0;
	ray.plane_x = cube->player->dir_y * -1 * 0.66;
	ray.plane_y = cube->player->dir_x * 0.66;
	while (i < SIZE_X)
	{
		ray.camera_x = 2 * i / (float)SIZE_X - 1.0f;
		ray.ray_dir_x = cube->player->dir_x + ray.plane_x * ray.camera_x;
		ray.ray_dir_y = cube->player->dir_y + ray.plane_y * ray.camera_x;
		next_wall_dist(cube, image, &ray);
		i++;
	}
}
