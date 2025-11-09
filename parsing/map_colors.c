/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:25:53 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/09 21:48:25 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_color(int *res, char **tab_color)
{
	int	r;
	int	g;
	int	b;

	if (*res == -1)
		return ;
	r = (int)ft_atoi(tab_color[0]);
	g = (int)ft_atoi(tab_color[1]);
	b = (int)ft_atoi(tab_color[2]);
	*res = ft_color(r, g, b);
}

static int	check_color(char *color)
{
	long	num;
	char	**color_tab;
	int		res;

	res = 0;
	color_tab = ft_split(color, ',');
	if (!color_tab)
		return (-1);
	if (ft_arrlen(color_tab) != 3)
	{
		ft_freeall(color_tab);
		return (-1);
	}
	num = ft_atoi(color_tab[0]);
	if (ft_strlen(color_tab[0]) > 4 && (num < 0 || num > 255))
		res = -1;
	num = ft_atoi(color_tab[1]);
	if (ft_strlen(color_tab[1]) > 4 && (num < 0 || num > 255))
		res = -1;
	num = ft_atoi(color_tab[2]);
	if (ft_strlen(color_tab[2]) > 4 && (num < 0 || num > 255))
		res = -1;
	get_color(&res, color_tab);
	ft_freeall(color_tab);
	return (res);
}

static int	parse_color(void *content, int *count)
{
	char	**split;
	int		res;

	(*count)++;
	split = ft_split(content, ' ');
	if (!(!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		|| ft_arrlen(split) != 2)
	{
		ft_freeall(split);
		return (-1);
	}
	res = check_color(split[1]);
	ft_freeall(split);
	return (res);
}

static char	*str_without_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (&s[i]);
}

/*Sauve et check les couleurs*/
void	parse_map_colors(t_map *map)
{
	t_list	*line;
	int		count;
	char	*without_space;

	count = 0;
	line = map->mapfile;
	while (line && line != map->map_start && line->content)
	{
		without_space = str_without_space((char *)line->content);
		if (count < 2)
		{
			if (!ft_strncmp(without_space, "C", 1))
				map->color_ceiling = parse_color(line->content, &count);
			else if (!ft_strncmp(without_space, "F", 1))
				map->color_floor = parse_color(line->content, &count);
		}
		else
		{
			if (!ft_strncmp(without_space, "C", 1))
				map->color_ceiling = -1;
			else if (!ft_strncmp(without_space, "F", 1))
				map->color_floor = -1;
		}
		line = line->next;
	}
}
