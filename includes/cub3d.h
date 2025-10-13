/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:14 by edurance          #+#    #+#             */
/*   Updated: 2025/10/13 11:25:21 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SIZE_X 800
# define SIZE_Y 600

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_cub
{
	void	*mlx;
	void	*mlx_window;
	char	**map;
	int		longest_line;
	int		nb_lines;
	int		mapcub_size;
	int		map_y;
	int		map_x;
}			t_cub;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/*minimap*/
int			get_mapsize(char *mapfile, t_cub *cub);
void		get_mapdata_display(t_cub *cub);
void		create_map(t_cub *cube, char *mapfile);

/*utils*/
int			ft_color(int r, int g, int b);

#endif
