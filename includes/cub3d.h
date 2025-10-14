/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:14 by edurance          #+#    #+#             */
/*   Updated: 2025/10/14 12:50:13 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SIZE_X 800
# define SIZE_Y 600

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>

typedef struct s_ply
{
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	int		side;
}			t_ply;

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
	t_ply	*player;
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
int			display_minimap(t_cub *cube);

/*utils*/
int			ft_color(int r, int g, int b);
void		put_pixel(t_data *data, int x, int y, int color);
void		ft_drawline(float *a, float *b, t_data *image);

/*player*/
int			init_player_data(t_cub *cube);

/*key hook*/
int			ft_key_hook(t_win_list *win, int (*funct)(), void *param);
int			key_hooks(int key, t_cub *cube);

/*DDA : Digital Differential Analysis*/
void		init_dda_datas(t_ply *ply);
void		next_wall_dist(t_cub *cube, t_data *image);

#endif
