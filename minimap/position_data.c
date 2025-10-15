/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:47:53 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 14:59:07 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_angle(t_cub *cube, char c)
{
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
}

int	init_player_data(t_cub *cube)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			c = cube->map[y][x];
			if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
			{
				cube->player->pos_x = x + 0.5f;
				cube->player->pos_y = y + 0.5f;
				return (player_angle(cube, c), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
