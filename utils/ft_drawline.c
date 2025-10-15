/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:24:27 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/15 14:54:13 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drawline(float *a, float *b, t_data *image)
{
	int		steps;
	float	step[2];
	int		i;
	float	x;
	float	y;

	steps = (int)ft_maxf(fabsf(b[0] - a[0]), fabsf(b[1] - a[1]));
	step[0] = (b[0] - a[0]) / steps;
	step[1] = (b[1] - a[1]) / steps;
	x = a[0];
	y = a[1];
	i = 0;
	while (i < steps)
	{
		put_pixel(image, (int)(x + 0.5f), (int)(y + 0.5f), ft_color(0, 0, 255));
		x += step[0];
		y += step[1];
		i++;
	}
}
