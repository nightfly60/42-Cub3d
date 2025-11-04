/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:18:30 by edurance          #+#    #+#             */
/*   Updated: 2025/11/04 16:04:08 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*convertir le rgb -> hexadecimal*/
int	ft_color(int r, int g, int b)
{
	if (r > 255 || r < 0)
		return (-1);
	if (g > 255 || g < 0)
		return (-1);
	if (b > 255 || b < 0)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
