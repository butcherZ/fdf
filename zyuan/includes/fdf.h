/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/02/13 16:47:08 by butcherz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 768

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
	int		x;
	int		y;
	int		z;
}		t_vector;

typedef	struct	s_info
{
	int		height;
	int		width;
	int		total;
}		t_info;
typedef struct	s_iso
{
	int	x;
	int	y;
	int	z;
}		t_iso;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int 	size_scale;
	t_img		img;
	t_vector	*vector;
	t_info		info;
	t_iso		iso;
}				t_mlx;


void			init_image(t_mlx *mlx);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab, t_info *info);
t_vector		*parse_file(int fd, char **line, t_info *info);
#endif
