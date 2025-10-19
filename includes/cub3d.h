/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:14 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 13:23:33 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef SIZE_X
#  define SIZE_X 1920
# endif

# ifndef SIZE_Y
#  define SIZE_Y 1081
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
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
}				t_ply;

typedef struct s_ray
{
	float		ray_dir_x;
	float		ray_dir_y;
	float		camera_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	float		sidedist_x;
	float		sidedist_y;
	float		deltadist_x;
	float		deltadist_y;
	float		plane_x;
	float		plane_y;
	float		perp_wall_dist;
	float		wall_x;
	int			side;
	int			text_x;
	int			line_height;
	float		draw_start;
	float		draw_end;
}				t_ray;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_line;
	int			end;
	int			width;
	int			height;
}				t_data;

typedef struct s_textures
{
	t_data		*north;
	t_data		*south;
	t_data		*east;
	t_data		*west;
	int			floor_color;
	int			ceiling_color;
}				t_textures;

typedef struct s_map
{
	t_list		*mapfile;
}				t_map;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_window_game;
	void		*img_minimap;
	void		*img_game;
	char		**map;
	int			longest_line;
	int			nb_lines;
	int			mapcub_size;
	int			map_y;
	int			map_x;
	int			minimap_sizex;
	int			minimap_sizey;
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_west;
	t_ply		*player;
	t_textures	*textures;
	char		*fps;
}				t_cub;

/*minimap*/
int				get_mapsize(char *mapfile, t_cub *cub);
void			get_mapdata_display(t_cub *cub);
void			create_map(t_cub *cube, char *mapfile);
void			map_background(t_cub *cube, t_data *image);
void			map_player(t_cub *cube, t_data *image, int ray);

/*utils*/
int				ft_color(int r, int g, int b);
void			put_pixel(t_data *data, int x, int y, int color);
void			ft_drawline(float *a, float *b, t_data *image, int color);
void			exit_game(t_cub *cub);
int				close_game(void *cub);
void			init_game(t_cub *cube, char **av);
int				get_pixel_color(t_data *data, int x, int y);

/*player*/
int				init_player_data(t_cub *cube);

/*keys and movements*/
int				key_hooks(int key, t_cub *cube);
void			ply_movements(int key, t_ply *ply, t_cub *cube);
void			ply_directions(int key, t_ply *ply);
int				mouse_moves(int x, int y, t_cub *cube);

/*DDA : Digital Differential Analysis*/
void			launch_rays(t_cub *cube, t_data *image_minimap,
					t_data *image_game);

/*game*/
int				display_game(t_cub *cube);
void			display_fisheye(t_ray *ray, t_data *image, int x, t_cub *cube);
void			display_fps(t_cub *cube);
void			display_game_bg(t_cub *cube, t_data *image);
void			display_crosshair(t_data *img);
void			init_textures(t_cub *cube);

/*parsing*/
int				get_filemap(char *path, t_map *map);
char			**get_map(t_map *map);

#endif
