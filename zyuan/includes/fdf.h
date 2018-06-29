/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/25 14:04:34 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"

#define WIN_WIDTH	2000
#define WIN_HEIGHT 	1000

#define IMG_WIDTH  (WIN_WIDTH - 300)
#define IMG_HEIGHT  WIN_HEIGHT

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

typedef	double	MATRIX [4][4];
typedef struct s_img
{
	void 		*img_ptr;
	int			*addr;
	int 		bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_vector
{
	float		x;
	float		y;
	float		z;
}		t_vector;

typedef	struct	s_info
{
	int		height;
	int		width;
	int		total;
	int		min_z;
	int		max_z;
	int		range_z;

}		t_info;

typedef struct	s_iso
{
	float	x;
	float	y;
	float	z;
	float	w;
}		t_iso;

typedef	struct s_fac
{
	int	scale;
	int	translation_x;
	int	translation_y;
	int	translation_z;
	int	altitude;
	int	rotation_x;
	int	rotation_y;
	int	rotation_z;
}		t_fac;

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
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			color;
	char		*argv;
	int         trigger;
	int         index;
	t_img		img;
	t_vector	*vector;
	t_vector	*origin;
	t_info		info;
	t_iso		iso;
	t_fac		fac;
	t_line		line;
}				t_mlx;
void			scale(t_iso *iso, int factor);
void			rotation_x(t_mlx *map, t_iso *iso);
void			rotation_y(t_mlx *map, t_iso *iso);
void			rotation_z(t_mlx *map, t_iso *iso);
void			translation(t_mlx *map, t_iso *iso);
void			init_image(t_mlx *mlx);
t_vector 		new_vector(int x, int y, int z);
t_line			init_line(t_vector *vect0, t_vector *vect1);
void			draw_line(t_vector *vect0, t_vector *vect1, t_mlx *map);
void 			draw_horizontal_line(t_iso *iso, t_mlx *map, int i);
void 			draw_vertical_line(t_iso *iso, t_mlx *map, int i);
void			get_coordinates(t_mlx *map, t_iso *iso);
void			key_rotation(int keycode, t_mlx *map);
void 			key_translation(int keycode, t_mlx *map);
int				key_long_press(int keycode, t_mlx *map);
int				key_down(int keycode, t_mlx *map);
void			empty(t_mlx *mlx);
void			draw_map(t_mlx *map);
void 			reset(t_mlx *map);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab, t_info *info);
t_vector		*parse_file(int fd, char **line, t_info *info);
#endif
