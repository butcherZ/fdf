/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:38:49 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/29 16:40:43 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

t_vector	new_vector(int x, int y, int z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_line		init_line(t_vector *vect0, t_vector *vect1)
{
	t_line	nl;

	nl.x0 = (int)vect0->x;
	nl.y0 = (int)vect0->y;
	nl.x1 = (int)vect1->x;
	nl.y1 = (int)vect1->y;
	nl.z0 = (int)vect0->z;
	nl.z1 = (int)vect1->z;
	nl.dx = abs(nl.x1 - nl.x0);
	nl.sx = (nl.x0 < nl.x1) ? 1 : -1;
	nl.dy = abs(nl.y1 - nl.y0);
	nl.sy = (nl.y0 < nl.y1) ? 1 : -1;
	nl.err = ((nl.dx > nl.dy) ? nl.dx : -nl.dy) / 2;
	return (nl);
}

void		color_altitude(t_mlx *map, t_line l)
{
	if (l.z0 != map->info.max_z || l.z0 != l.z1)
	{
		if (l.z0 > map->info.max_z / 2 && l.z1 > map->info.max_z / 2)
		{
			img_put_pixel(map, l.x0, l.y0, 0x6dd5ed);
		}
		else
			img_put_pixel(map, l.x0, l.y0, 0x4286f4);
	}
	else
		img_put_pixel(map, l.x0, l.y0, 0x7F7FD5);
}

void		draw_line(t_vector *vect0, t_vector *vect1, t_mlx *map)
{
	t_line	l;

	l = init_line(vect0, vect1);
	while (1)
	{
		color_altitude(map, l);
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		l.err2 = l.err;
		if (l.err2 > -l.dx)
		{
			l.err -= l.dy;
			l.x0 += l.sx;
		}
		if (l.err2 < l.dy)
		{
			l.err += l.dx;
			l.y0 += l.sy;
		}
	}
}
