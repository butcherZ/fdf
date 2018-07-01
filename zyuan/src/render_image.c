/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:43:19 by zyuan             #+#    #+#             */
/*   Updated: 2018/07/01 15:53:41 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		manipulation(t_mlx *map, t_iso *iso)
{
	iso_reduction(iso, map->info.width, map->info.height);
	scale(iso, map->fac.scale);
	rotation_x(map, iso);
	rotation_y(map, iso);
	rotation_z(map, iso);
	iso_augmentation(iso, map->info.width, map->info.height);
	translation(map, iso);
}

void		get_coordinates(t_mlx *map, t_iso *iso)
{
	int		i;

	i = 0;
	while (i < map->info.total)
	{
		if (map->vector[i].z != 0)
		{
			altitude_plus(&map->vector[i], map);
		}
		iso[i].x = map->vector[i].x;
		iso[i].y = map->vector[i].y;
		iso[i].z = map->vector[i].z;
		manipulation(map, &iso[i]);
		i++;
	}
	get_z(map);
	map->fac.altitude = 0;
}

void		draw_horizontal_line(t_iso *iso, t_mlx *map, int i)
{
	t_vector	vect0;
	t_vector	vect1;

	vect0 = new_vector((int)iso[i].x, (int)iso[i].y, (int)map->vector[i].z);
	vect1 = new_vector((int)iso[i + 1].x,
			(int)iso[i + 1].y, (int)map->vector[i + 1].z);
	draw_line(&vect0, &vect1, map);
}

void		draw_vertical_line(t_iso *iso, t_mlx *map, int i)
{
	t_vector	vect0;
	t_vector	vect1;

	vect0 = new_vector((int)iso[i].x, (int)iso[i].y, map->vector[i].z);
	vect1 = new_vector((int)iso[i + map->info.width].x,
			(int)iso[i + map->info.width].y,
			(int)map->vector[i + map->info.width].z);
	draw_line(&vect0, &vect1, map);
}

void		draw_map(t_mlx *map)
{
	int			i;
	t_iso		*iso;

	i = 0;
	if (!(iso = malloc(sizeof(t_iso) * map->info.total)))
		exit(1);
	get_coordinates(map, iso);
	while (i < map->info.total)
	{
		if (i % map->info.width != map->info.width - 1)
			draw_horizontal_line(iso, map, i);
		if (map->info.total - i > map->info.width)
			draw_vertical_line(iso, map, i);
		i++;
	}
	free(iso);
}
