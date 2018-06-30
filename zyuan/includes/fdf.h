/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/30 15:35:48 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000

# define IMG_WIDTH (WIN_WIDTH - 300)
# define IMG_HEIGHT WIN_HEIGHT

# define DEGTORAD(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
# define RADTODEG(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

typedef struct	s_img
{
	void		*img_ptr;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef	struct	s_info
{
	int			height;
	int			width;
	int			total;
	int			min_z;
	int			max_z;
	int			range_z;
	int			error;

}				t_info;

typedef struct	s_iso
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_iso;

typedef	struct	s_fac
{
	int			scale;
	int			translation_x;
	int			translation_y;
	int			translation_z;
	int			altitude;
	int			rotation_x;
	int			rotation_y;
	int			rotation_z;
}				t_fac;

typedef	struct	s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			z0;
	int			z1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef	struct	s_matrix
{
	double		value[4][4];
}				t_matrix;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			color;
	char		*argv;
	int			trigger;
	int			index;
	int			fd;
	char		*read_line;
	t_img		img;
	t_vector	*vector;
	t_vector	*origin;
	t_info		info;
	t_iso		iso;
	t_fac		fac;
	t_line		line;
}				t_mlx;

/*
** read file read.c
*/

void			initiate_info(t_info *info);
void			free_tab(char **tab, t_info *info);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab,
		t_info *info);
t_vector		*parse_file(int fd, char **line, t_info *info);

/*
** initialize matrices init_matrices.c
*/

t_matrix		rotation_x_matrix(t_mlx *map);
t_matrix		rotation_y_matrix(t_mlx *map);
t_matrix		rotation_z_matrix(t_mlx *map);
t_matrix		translation_matrix(t_mlx *map);

/*
**  matrices applications matrices.c
*/

void			scale(t_iso *iso, int factor);
void			rotation_x(t_mlx *map, t_iso *iso);
void			rotation_y(t_mlx *map, t_iso *iso);
void			rotation_z(t_mlx *map, t_iso *iso);
void			translation(t_mlx *map, t_iso *iso);

/*
**  altitude manipulations change_altitude.c
*/

void			get_z(t_mlx *map);
void			altitude_plus(t_vector *vec, t_mlx *map);

/*
**  draw lines draw_line.c
*/

t_vector		new_vector(int x, int y, int z);
t_line			init_line(t_vector *vect0, t_vector *vect1);
void			color_altitude(t_mlx *map, t_line l);
void			draw_line(t_vector *vect0, t_vector *vect1, t_mlx *map);

/*
**  set up env for image set_up_image.c
*/

void			init_image(t_mlx *mlx);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
void			empty(t_mlx *mlx);
void			iso_reduction(t_iso *iso, int x, int y);
void			iso_augmentation(t_iso *iso, int x, int y);

/*
**  render image render_image.c
*/

void			manipulation(t_mlx *map, t_iso *iso);
void			get_coordinates(t_mlx *map, t_iso *iso);
void			draw_horizontal_line(t_iso *iso, t_mlx *map, int i);
void			draw_vertical_line(t_iso *iso, t_mlx *map, int i);
void			draw_map(t_mlx *map);

/*
**  key functions key_functions.c
*/

void			print_key_usage(int keycode);
void			key_rotation(int keycode, t_mlx *map);
void			key_translation(int keycode, t_mlx *map);
int				key_long_press(int keycode, t_mlx *map);
int				key_down(int keycode, t_mlx *map);

/*
**  reset map main.c
*/

void			reset(t_mlx *map);

/*
**  print usage on the window main.c
*/

void			print_usage(t_mlx *map);

/*
**  loop hook for animation main.c
*/

int				mlx_while(t_mlx *map);

/*
**  stupid function to call everything, FOR THE NORM main.c
*/

void			call_everything(t_mlx *map);
#endif
