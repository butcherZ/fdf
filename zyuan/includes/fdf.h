/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/23 23:03:56 by butcherz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 768

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

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			color;
	t_img		img;
	t_vector	*vector;
	t_vector	*origin;
	t_info		info;
	t_iso		iso;
	t_fac		fac;
}				t_mlx;

void			init_image(t_mlx *mlx);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab, t_info *info);
t_vector		*parse_file(int fd, char **line, t_info *info);
#endif
