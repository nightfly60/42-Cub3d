/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:27:07 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 14:54:47 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_cub *cub)
{
	if (cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx, cub->mlx_window);
	free(cub->player);
	ft_freeall(cub->map);
	free(cub->mlx);
	free(cub);
	printf("And thanks for all the fish!\n");
	exit(0);
}
