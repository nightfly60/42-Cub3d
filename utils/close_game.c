/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:46 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 15:36:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*exit game avec void * en param pour le hook (croix en haut a droite)*/
int	close_game(void *cub)
{
	exit_game((t_cub *)cub);
	return (0);
}
