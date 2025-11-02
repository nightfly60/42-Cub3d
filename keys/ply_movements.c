/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:50:30 by edurance          #+#    #+#             */
/*   Updated: 2025/11/02 11:07:03 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Gere les mouvements mediaux*/
static void	medial_moves(int key, t_ply *ply, t_cub *cub)
{
	float	steps;
	float	next_x;
	float	next_y;
	int		direction;

	steps = 0.1f;
	if (key == XK_w)
		direction = 1;
	if (key == XK_s)
		direction = -1;
	next_x = ply->pos_x + ply->dir_x * steps * direction;
	next_y = ply->pos_y + ply->dir_y * steps * direction;
	if (cub->map[(int)(next_y)][(int)next_x]
		&& cub->map[(int)(next_y)][(int)next_x] != '1')
	{
		ply->pos_x = next_x;
		ply->pos_y = next_y;
	}
}

/*Gere les mouvements lateraux*/
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
	if (cub->map[(int)(next_y)][(int)next_x]
		&& cub->map[(int)(next_y)][(int)next_x] != '1')
	{
		pl->pos_x = next_x;
		pl->pos_y = next_y;
	}
}

/*Gere les mouvements du joueur*/
void	ply_movements(int key, t_ply *ply, t_cub *cube)
{
	if (key == XK_w || key == XK_s)
		medial_moves(key, ply, cube);
	else if (key == XK_a || key == XK_d)
		lateral_moves(key, ply, cube);
}
