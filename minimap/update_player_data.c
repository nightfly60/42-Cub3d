/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:40:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/14 11:35:53 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clc_step_side(t_ply *ply)
{
	if (ply->dirX >= 0)
	{
		ply->stepX = 1;
		ply->sideDistX = (ply->mapX + 1.0f - ply->posX) * ply->deltaDistX;
	}
	else
	{
		ply->stepX = -1;
		ply->sideDistX = (ply->posX - ply->mapX) * ply->deltaDistX;
	}
	if (ply->dirY >= 0)
	{
		ply->stepY = 1;
		ply->sideDistY = (ply->mapY + 1.0f - ply->posY) * ply->deltaDistY;
	}
	else
	{
		ply->stepY = -1;
		ply->sideDistY = (ply->posY - ply->mapY) * ply->deltaDistY;
	}
}

void	init_dda_datas(t_ply *ply)
{
	ply->mapX = (int)ply->posX;
	ply->mapY = (int)ply->posY;
	if (ply->dirX)
		ply->deltaDistX = fabsf(1 / ply->dirX);
	else
		ply->deltaDistX = FLT_MAX;
	if (ply->dirY)
		ply->deltaDistY = fabsf(1 / ply->dirY);
	else
		ply->deltaDistY = FLT_MAX;
	clc_step_side(ply);
	// printf("Step X = %d || Step Y = %d\n", ply->stepX, ply->stepY);
	// printf("SidDirX = %f || SideDirY = %f\n", ply->sideDistX, ply->sideDistY);
	// printf("mapX = %d || mapY = %d\n", ply->mapX, ply->mapY);
	// printf("deltaDistX = %f || deltaDistY = %f\n", ply->deltaDistX, ply->deltaDistY);
	// printf("posx = %f posy = %f angX = %f angY = %f\n", ply->posX, ply->posY, ply->dirX, ply->dirY);
}

void	next_wall_dist(t_cub *cube)
{
	int		wall;
	t_ply	*ply;
	int		side;

	ply = cube->player;
	init_dda_datas(ply);
	wall = 0;
	while (!wall)
	{
		if (ply->sideDistX < ply->sideDistY)
		{
			ply->sideDistX = ply->sideDistX + ply->deltaDistX;
			ply->mapX += ply->stepX;
			side = 0;
		}
		else
		{
			ply->sideDistY += ply->deltaDistY;
			ply->mapY += ply->stepY;
			side = 1;
		}
		if (cube->map[ply->mapY][ply->mapX] == '1')
			wall = 1;
	}
}
