/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:37 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/13 15:03:38 by aabouyaz         ###   ########.fr       */
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
	if (key == XK_w)
	{
		cube->player->posX += 0.1f;
	}
	return (0);
}
