/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fisheye.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:28:08 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 16:44:39 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_fisheye(t_ray *ray, t_data *image, int x)
{
	float	pos_a[2];
	float	pos_b[2];

	pos_a[0] = x;
	pos_b[0] = x;
	pos_a[1] = (float)((-1 * ray->line_height) / 2 + SIZE_Y / 2);
	if (pos_a[1] < 0)
		pos_a[1] = 0;
	pos_b[1] = (float)(ray->line_height / 2 + SIZE_Y / 2);
	if (pos_b[1] >= SIZE_Y)
		pos_b[1] = SIZE_Y - 1;
	if (ray->side)
		ft_drawline(pos_a, pos_b, image, ft_color(100, 35, 230));
	else
		ft_drawline(pos_a, pos_b, image, ft_color(153, 153, 0));
}
