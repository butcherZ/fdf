/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:33 by zyuan             #+#    #+#             */
/*   Updated: 2018/01/08 18:52:50 by zyuan            ###   ########.fr       */
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

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_img		img;
}				t_mlx;
#endif
