/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:01:52 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/30 12:05:56 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_matrix		rotation_x_matrix(t_mlx *map)
{
	t_matrix	m;

	ft_bzero(m.value, sizeof(m.value));
	m.value[0][0] = 1.0;
	m.value[1][1] = cos(DEGTORAD(map->fac.rotation_x));
	m.value[1][2] = -sin(DEGTORAD(map->fac.rotation_x));
	m.value[2][1] = sin(DEGTORAD(map->fac.rotation_x));
	m.value[2][2] = cos(DEGTORAD(map->fac.rotation_x));
	m.value[2][3] = 1.0;
	m.value[3][3] = 1.0;
	return (m);
}

t_matrix		rotation_y_matrix(t_mlx *map)
{
	t_matrix		m;

	ft_bzero(m.value, sizeof(m.value));
	m.value[0][0] = cos(DEGTORAD(map->fac.rotation_y));
	m.value[0][2] = sin(DEGTORAD(map->fac.rotation_y));
	m.value[1][1] = 1.0;
	m.value[2][0] = -sin(DEGTORAD(map->fac.rotation_y));
	m.value[2][2] = cos(DEGTORAD(map->fac.rotation_y));
	m.value[2][3] = 1.0;
	m.value[3][3] = 1.0;
	return (m);
}

t_matrix		rotation_z_matrix(t_mlx *map)
{
	t_matrix m;

	ft_bzero(m.value, sizeof(m.value));
	m.value[0][0] = cos(DEGTORAD(map->fac.rotation_z));
	m.value[0][1] = -sin(DEGTORAD(map->fac.rotation_z));
	m.value[1][0] = sin(DEGTORAD(map->fac.rotation_z));
	m.value[1][1] = cos(DEGTORAD(map->fac.rotation_z));
	m.value[2][3] = 1.0;
	m.value[3][3] = 1.0;
	return (m);
}

t_matrix		translation_matrix(t_mlx *map)
{
	t_matrix m;

	ft_bzero(m.value, sizeof(m.value));
	m.value[0][0] = 1.0;
	m.value[0][3] = map->fac.translation_x;
	m.value[1][1] = 1.0;
	m.value[1][3] = map->fac.translation_y;
	m.value[2][2] = 1.0;
	m.value[2][3] = map->fac.translation_z;
	m.value[3][3] = 1;
	return (m);
}
