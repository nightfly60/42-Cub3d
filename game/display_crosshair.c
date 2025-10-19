/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_crosshair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:27:41 by edurance          #+#    #+#             */
/*   Updated: 2025/10/17 12:48:35 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_crosshair(t_data *img)
{
	float	a[2];
	float	b[2];

	a[0] = SIZE_X / 2;
	a[1] = SIZE_Y / 2 - 10;
	b[0] = SIZE_X / 2;
	b[1] = SIZE_Y / 2 + 11;
	ft_drawline(a, b, img, ft_color(0, 0, 0));
	a[0] = SIZE_X / 2 - 10;
	a[1] = SIZE_Y / 2;
	b[0] = SIZE_X / 2 + 11;
	b[1] = SIZE_Y / 2;
	ft_drawline(a, b, img, ft_color(0, 0, 0));
}
