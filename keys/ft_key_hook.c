/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:26:37 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/15 15:08:26 by edurance         ###   ########.fr       */
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
