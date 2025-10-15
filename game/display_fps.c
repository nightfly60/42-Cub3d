/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:54:53 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 17:55:33 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static long	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	display_fps(t_cub *cube)
{
	static int	fps = 0;
	static long	last_time = 0;
	long		time;

	time = get_timestamp();
	if (!last_time)
	{
		last_time = time;
		return ;
	}
	if (last_time + 1000 <= time)
	{
		free(cube->fps);
		cube->fps = NULL;
		cube->fps = ft_itoa(fps);
		last_time = time;
		fps = 1;
	}
	else
		fps++;
	if (cube->fps)
		mlx_string_put(cube->mlx, cube->mlx_window_game, SIZE_X - 25, 15,
			ft_color(255, 255, 255), cube->fps);
}
