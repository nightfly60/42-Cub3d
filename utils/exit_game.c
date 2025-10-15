/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:27:07 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 16:14:45 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Fonction pour exit cub3d proprement*/
void	exit_game(t_cub *cub)
{
	if (cub->img_minimap)
		mlx_destroy_image(cub->mlx, cub->img_minimap);
	if (cub->img_game)
		mlx_destroy_image(cub->mlx, cub->img_game);
	if (cub->mlx_window_minimap)
		mlx_destroy_window(cub->mlx, cub->mlx_window_minimap);
	if (cub->mlx_window_game)
		mlx_destroy_window(cub->mlx, cub->mlx_window_game);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->player);
	ft_freeall(cub->map);
	free(cub->mlx);
	free(cub);
	printf("And thanks for all the fish!\n");
	exit(0);
}
