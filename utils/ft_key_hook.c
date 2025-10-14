/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:37 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/14 16:05:03 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[KeyPress].hook = funct;
	win->hooks[KeyPress].param = param;
	win->hooks[KeyPress].mask = KeyPressMask;
	return (0);
}

int	key_hooks(int key, t_cub *cube)
{
	t_ply	*ply;
	float	oldDirX;
	float	angle;

	ply = cube->player;
	oldDirX = ply->dirX;
	angle = 0.02f;
	if (key == XK_w)
	{
		if (cube->map[(int)(ply->posY + -0.1f)][(int)ply->posX] != '1')
			ply->posY += -0.1f;
	}
	else if (key == XK_Right)
	{
		ply->dirX = oldDirX * cosf(angle) - ply->dirY * sinf(angle);
		ply->dirY = oldDirX * sinf(angle) + ply->dirY * cosf(angle);
	}
	else if (key == XK_Left)
	{
		ply->dirX = oldDirX * cosf(angle * -1) - ply->dirY * sinf(angle * -1);
		ply->dirY = oldDirX * sinf(angle * -1) + ply->dirY * cosf(angle * -1);
	}
	else if (key == XK_Escape)
	{
		exit(0);
	}
	return (0);
}
