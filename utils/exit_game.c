/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:27:07 by edurance          #+#    #+#             */
/*   Updated: 2025/11/03 16:18:51 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_images(t_cub *cub)
{
	if (cub->textures && cub->textures->east && cub->textures->east->img)
		mlx_destroy_image(cub->mlx, cub->textures->east->img);
	if (cub->textures && cub->textures->west && cub->textures->west->img)
		mlx_destroy_image(cub->mlx, cub->textures->west->img);
	if (cub->textures && cub->textures->north && cub->textures->north->img)
		mlx_destroy_image(cub->mlx, cub->textures->north->img);
	if (cub->textures && cub->textures->south && cub->textures->south->img)
		mlx_destroy_image(cub->mlx, cub->textures->south->img);
	if (cub->img_minimap)
		mlx_destroy_image(cub->mlx, cub->img_minimap);
	if (cub->img_game)
		mlx_destroy_image(cub->mlx, cub->img_game);
	free(cub->textures->north);
	free(cub->textures->south);
	free(cub->textures->east);
	free(cub->textures->west);
}

/*Fonction pour exit cub3d proprement*/
void	exit_game(t_cub *cub)
{
	destroy_images(cub);
	mlx_mouse_show(cub->mlx, cub->mlx_window_game);
	if (cub->mlx_window_game)
		mlx_destroy_window(cub->mlx, cub->mlx_window_game);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	exit_map(cub->map_struct, NULL);
	free(cub->player);
	free(cub->path_east);
	free(cub->path_south);
	free(cub->path_north);
	free(cub->path_west);
	free(cub->textures);
	free(cub->mlx);
	free(cub->fps);
	free(cub);
	printf("And thanks for all the fish!\n");
	exit(0);
}
