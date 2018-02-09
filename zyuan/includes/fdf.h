/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/02/09 15:04:08 by butcherz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 500

typedef struct s_img
{
	void 		*img_ptr;
	int			*addr;
	int 		bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_coord
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_coord;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_img		img;
	t_coord		coord;
}				t_mlx;

typedef struct s_vector
{
	int		x;
	int		y;
	int		z;
}		t_vector;


void			init_image(t_mlx *mlx);
void			img_put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector		*realloc_and_append_struct(t_vector *vectors, char **tab, int total, int width);
t_vector		*parse_file(int fd, char **line);
#endif
