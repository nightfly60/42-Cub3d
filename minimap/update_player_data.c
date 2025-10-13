/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:40:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/13 16:08:23 by aabouyaz         ###   ########.fr       */
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
		ply->deltaDistX = 3.402823466e+38F;
	if (ply->dirY)
		ply->deltaDistY = fabsf(1 / ply->dirY);
	else
		ply->deltaDistY = 3.402823466e+38F;
	clc_step_side(ply);
}
