/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:28:03 by edurance          #+#    #+#             */
/*   Updated: 2025/10/17 12:36:57 by aabouyaz         ###   ########.fr       */
=======
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:28:03 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 15:17:39 by edurance         ###   ########.fr       */
>>>>>>> elena
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Dessin un pixel couleur au coords x et y de l'image*/
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

<<<<<<< HEAD
	dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->l_line + x * (data->bpp / 8));
	return ((int)*(unsigned int *)dst);
}
=======
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
>>>>>>> elena
