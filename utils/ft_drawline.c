/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:24:27 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/14 12:43:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_drawline(float *a, float *b, t_data *image)
{
	float	dx;
	float	dy;
	int		steps;
	float	stepX;
	float	stepY;
	int		i;
	float	x;
	float	y;

	dx = b[0] - a[0];
	dy = b[1] - a[1];
	steps = (int)ft_max(fabsf(dx), fabsf(dy));
	stepX = dx / steps;
	stepY = dy / steps;
	x = a[0];
	y = a[1];
	i = 0;
	while (i < steps)
	{
		put_pixel(image, (int)(x + 0.5f), (int)(y + 0.5f), ft_color(0, 0, 255));
		x += stepX;
		y += stepY;
		i++;
	}
}
