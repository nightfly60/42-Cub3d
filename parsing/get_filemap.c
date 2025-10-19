/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:19:46 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 13:20:40 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_filemap(char *path, t_map *map)
{
	int fd;
	t_list **filemap;
	char	*line;
	int	i;
	i = 0;

	if (ft_strcmp(&path[ft_strlen(path) - 4], ".cub"))
	{
		printf("Bad file name\n");
		return (1);
	}
	filemap = &map->mapfile;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Map couldnt open\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(filemap, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (0);
}
