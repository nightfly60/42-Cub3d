/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:12:12 by edurance          #+#    #+#             */
/*   Updated: 2025/11/04 17:16:24 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*recupere la longest line et le nb de lignes*/
int	get_mapsize(char *mapfile, t_cub *cub)
{
	int		nb_lines;
	int		lg_len;
	int		fd;
	int		line_len;
	char	*line;

	nb_lines = 0;
	lg_len = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		line_len = (int)ft_strlen(line) - 1;
		if (lg_len < line_len)
			lg_len = line_len;
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cub->longest_line = lg_len;
	cub->nb_lines = nb_lines;
	return (0);
}

/*quelle taille pour un cube ? a quelle position afficher la map ?*/
void	get_mapdata_display(t_cub *cub)
{
	int	cub_x;
	int	cub_y;

	cub_x = cub->minimap_sizex / cub->longest_line;
	cub_y = cub->minimap_sizey / cub->nb_lines;
	if (cub_x == 0 || cub_y == 0)
		cub->mapcub_size = 1;
	else if (cub_x < cub_y)
	{
		cub->map_x = 0;
		cub->map_y = (cub->minimap_sizey - cub_x * cub->nb_lines) / 2;
		cub->mapcub_size = cub_x;
	}
	else if (cub_x > cub_y)
	{
		cub->map_y = 0;
		cub->map_x = (cub->minimap_sizex - cub_y * cub->longest_line) / 2;
		cub->mapcub_size = cub_y;
	}
	else
	{
		cub->map_x = 0;
		cub->map_y = 0;
		cub->mapcub_size = cub_x;
	}
}
