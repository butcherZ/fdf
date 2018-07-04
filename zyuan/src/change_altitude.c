/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:01:16 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/30 12:15:35 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

void	get_z(t_mlx *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->info.max_z = map->vector[0].z;
	map->info.min_z = map->vector[0].z;
	while (i < map->info.total && j < map->info.total)
	{
		if (map->vector[i].z < map->info.max_z)
		{
			map->info.max_z = map->vector[i].z;
		}
		if (map->vector[j].z > map->info.min_z)
		{
			map->info.min_z = map->vector[j].z;
		}
		i++;
		j++;
	}
	map->info.range_z = abs(map->info.max_z - map->info.min_z);
}

void	altitude_plus(t_vector *vec, t_mlx *map)
{
	if (map->fac.altitude == 1)
		vec->z += 1;
	if (map->fac.altitude == 2)
		vec->z -= 1;
	if (map->fac.altitude == 2 && vec->z == 0)
		vec->z = -1;
	if (map->fac.altitude == 1 && vec->z == 0)
		vec->z = 1;
}
