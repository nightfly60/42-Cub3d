/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:47:53 by edurance          #+#    #+#             */
/*   Updated: 2025/11/03 15:42:25 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Initialise les donnes du player*/
int	init_player_data(t_cub *cube)
{
	char	c;

	c = cube->map_struct->start_dir;
	if (c == 'N')
	{
		cube->player->dir_x = 0.0f;
		cube->player->dir_y = -1.0f;
	}
	else if (c == 'W')
	{
		cube->player->dir_x = -1.0f;
		cube->player->dir_y = 0.0f;
	}
	else if (c == 'E')
	{
		cube->player->dir_x = 1.0f;
		cube->player->dir_y = 0.0f;
	}
	else if (c == 'S')
	{
		cube->player->dir_x = 0.0f;
		cube->player->dir_y = 1.0f;
	}
	return (0);
}
