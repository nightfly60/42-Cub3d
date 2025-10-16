/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:14 by edurance          #+#    #+#             */
/*   Updated: 2025/10/16 11:43:09 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef SIZE_X
#  define SIZE_X 1920
# endif

# ifndef SIZE_Y
#  define SIZE_Y 1080
# endif

# ifndef M_PI
#  define M_PI 3.14159265359f
# endif

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_ply
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
}			t_ply;

typedef struct s_ray
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	camera_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	sidedist_x;
	float	sidedist_y;
	float	deltadist_x;
	float	deltadist_y;
	float	plane_x;
	float	plane_y;
	float	perp_wall_dist;
	int		side;
	int		line_height;
}			t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_line;
	int		end;
}			t_data;

typedef struct s_cub
{
	void	*mlx;
	void	*mlx_window_minimap;
	void	*mlx_window_game;
	void	*img_minimap;
	void	*img_game;
	char	**map;
	int		longest_line;
	int		nb_lines;
	int		mapcub_size;
	int		map_y;
	int		map_x;
	int		floor_color;
	int		ceiling_color;
	int		minimap_sizex;
	int		minimap_sizey;
	t_ply	*player;
	char	*fps;
}			t_cub;

/*minimap*/
int			get_mapsize(char *mapfile, t_cub *cub);
void		get_mapdata_display(t_cub *cub);
void		create_map(t_cub *cube, char *mapfile);
void		map_background(t_cub *cube, t_data *image);
void		map_player(t_cub *cube, t_data *image, int ray);

/*utils*/
int			ft_color(int r, int g, int b);
void		put_pixel(t_data *data, int x, int y, int color);
void		ft_drawline(float *a, float *b, t_data *image, int color);
void		exit_game(t_cub *cub);
int			close_game(void *cub);

/*player*/
int			init_player_data(t_cub *cube);

/*keys and movements*/
int			key_hooks(int key, t_cub *cube);
void		ply_movements(int key, t_ply *ply, t_cub *cube);
void		ply_directions(int key, t_ply *ply);

/*DDA : Digital Differential Analysis*/
void		launch_rays(t_cub *cube, t_data *image_minimap, t_data *image_game);

/*game*/
int			display_game(t_cub *cube);
void		display_fisheye(t_ray *ray, t_data *image, int x);
void		display_fps(t_cub *cube);
void		display_game_bg(t_cub *cube, t_data *image);

#endif
