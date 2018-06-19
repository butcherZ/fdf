/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/14 16:26:20 by zyuan            ###   ########.fr       */
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
}		t_iso;

typedef	struct s_fac
{
	int	scale;
	int	translation_x;
	int	translation_y;
	int	altitude;
}		t_fac;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_img		img;
	t_vector	*vector;
	t_info		info;
	t_iso		iso;
	t_fac		fac;
}				t_mlx;

void			init_image(t_mlx *mlx);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab, t_info *info);
t_vector		*parse_file(int fd, char **line, t_info *info);
void    horizontalright(t_mlx *map, t_iso first, t_iso second, int color);
void    horizontalleft(t_mlx *map, t_iso first, t_iso second, int color);
void    brasenham2(t_mlx *map, t_iso first, t_iso second, int color);
void    brasenham(t_mlx *map, t_iso first, t_iso second, int color);
void    firsto(t_mlx *map, t_iso first, t_iso second, int color);
void    secondo(t_mlx *map, t_iso first, t_iso second, int color);
void    thirdo(t_mlx *map, t_iso first, t_iso second, int color);
void    fourtho(t_mlx *map, t_iso first, t_iso second, int color);
void    fiftho(t_mlx *map, t_iso first, t_iso second, int color);
void    sixtho(t_mlx *map, t_iso first, t_iso second, int color);
void    seveno(t_mlx *map, t_iso first, t_iso second, int color);
void    eighto(t_mlx *map, t_iso first, t_iso second, int color);
void    verticaldown(t_mlx *map, t_iso first, t_iso second, int color);
void    verticalup(t_mlx *map, t_iso first, t_iso second, int color);
#endif
