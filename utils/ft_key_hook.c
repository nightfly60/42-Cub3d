/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:37 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:11:00 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Recup la key qui a ete press et la traite*/
int	key_hooks(int key, t_cub *cube)
{
	t_ply	*ply;

	ply = cube->player;
	if (key == XK_w)
	{
		if (cube->map[(int)(ply->posY + -0.1f)][(int)ply->posX] != '1')
			ply->posY += -0.1f;
	}
	else if (key == XK_Left)
	{
		ply->dirX += 0.1f;
		ply->dirY += -0.1f;
	}
	else if (key == XK_Right)
	{
		ply->dirX += -0.1f;
		ply->dirY += 0.1f;
	}
	return (0);
}
