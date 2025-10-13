/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:47:53 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 12:26:40 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_angle(t_cub *cube, char c)
{
	if (c == 'N')
	{
		cube->player->dirX = 0.0f;
		cube->player->dirY = 1.0f;
	}
	else if (c == 'W')
	{
		cube->player->dirX = -1.0f;
		cube->player->dirY = 0.0f;
	}
	else if (c == 'E')
	{
		cube->player->dirX = 1.0f;
		cube->player->dirY = 0.0f;
	}
	else if (c == 'S')
	{
		cube->player->dirX = 0.0f;
		cube->player->dirY = -1.0f;
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
				cube->player->posX = x + 0.5f;
				cube->player->posY = y + 0.5f;
				return (player_angle(cube, c), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
