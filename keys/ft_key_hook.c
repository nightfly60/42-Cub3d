/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:37 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/17 13:20:56 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*hook pour les mouvements, directions, et Escape*/
int	key_hooks(int key, t_cub *cube)
{
	t_ply	*ply;

	ply = cube->player;
	if (key == XK_w || key == XK_a || key == XK_s || XK_d == key)
		ply_movements(key, ply, cube);
	else if (key == XK_Right || key == XK_Left)
		ply_directions(key, ply);
	else if (key == XK_Escape)
		exit_game(cube);
	return (0);
}

int	mouse_moves(int x, int y, t_cub *cube)
{
	static int	old_x = 0;
	float		old_dir_x;
	float		angle;
	t_ply		*pl;

	pl = cube->player;
	angle = 0.02f;
	old_dir_x = pl->dir_x;
	(void)y;
	if (old_x == 0)
		old_x = x;
	else if (x < old_x && old_x - x > 10)
	{
		pl->dir_x = old_dir_x * cosf(angle * -1) - pl->dir_y * sinf(angle * -1);
		pl->dir_y = old_dir_x * sinf(angle * -1) + pl->dir_y * cosf(angle * -1);
	}
	else if (x > old_x && x - old_x > 10)
	{
		pl->dir_x = old_dir_x * cosf(angle) - pl->dir_y * sinf(angle);
		pl->dir_y = old_dir_x * sinf(angle) + pl->dir_y * cosf(angle);
	}
	else
		old_x = x;
	return (0);
}
