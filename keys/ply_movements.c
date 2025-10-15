/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:50:30 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 15:02:25 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	medial_moves(int key, t_ply *ply, t_cub *cub)
{
	float	steps;
	float	next_x;
	float	next_y;

	steps = 0.1f;
	if (key == XK_w)
	{
		next_x = ply->pos_x + ply->dir_x * steps;
		next_y = ply->pos_y + ply->dir_y * steps;
		if (cub->map[(int)(next_y)][(int)next_x] != '1')
		{
			ply->pos_x = next_x;
			ply->pos_y = next_y;
		}
	}
	if (key == XK_s)
	{
		next_x = ply->pos_x + ply->dir_x * steps * -1;
		next_y = ply->pos_y + ply->dir_y * steps * -1;
		if (cub->map[(int)(next_y)][(int)next_x] != '1')
		{
			ply->pos_x = next_x;
			ply->pos_y = next_y;
		}
	}
}

static void	lateral_moves(int key, t_ply *pl, t_cub *cub)
{
	float	steps;
	float	next_x;
	float	next_y;
	float	ax;
	float	ay;

	steps = 0.1f;
	ax = pl->dir_x * cosf((M_PI / 2) * -1) - pl->dir_y * sinf((M_PI / 2) * -1);
	ay = pl->dir_x * sinf((M_PI / 2) * -1) + pl->dir_y * cosf((M_PI / 2) * -1);
	if (key == XK_a)
	{
		next_x = pl->pos_x + ax * steps;
		next_y = pl->pos_y + ay * steps;
	}
	else
	{
		next_x = pl->pos_x - ax * steps;
		next_y = pl->pos_y - ay * steps;
	}
	if (cub->map[(int)(next_y)][(int)next_x] != '1')
	{
		pl->pos_x = next_x;
		pl->pos_y = next_y;
	}
}

void	ply_movements(int key, t_ply *ply, t_cub *cube)
{
	if (key == XK_w || key == XK_s)
		medial_moves(key, ply, cube);
	else if (key == XK_a || key == XK_d)
		lateral_moves(key, ply, cube);
}
