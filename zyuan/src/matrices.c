/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:17:27 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/26 15:24:17 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		scale(t_iso *iso, int factor)
{
			iso->x = iso->x * factor;
			iso->y = iso->y * factor;
			iso->z = iso->z * factor;
}
void		rotation_x(t_mlx *map, t_iso *iso)
{
			t_matrix m;

			m = rotation_x_matrix(map);

			iso->x = (int) (iso->x * m.value[0][0] + iso->y * m.value[0][1] + iso->z * m.value[0][2] + m.value[0][3]);
			iso->y = (int) (iso->x * m.value[1][0] + iso->y * m.value[1][1] + iso->z * m.value[1][2] + m.value[1][3]);
			iso->z = (int) (iso->x * m.value[2][0] + iso->y * m.value[2][2] + iso->z * m.value[2][2] + m.value[2][3]);

}

void	rotation_y(t_mlx *map, t_iso *iso)
{
		t_matrix m;

		m = rotation_y_matrix(map);

		iso->x = (int) (iso->x * m.value[0][0] + iso->y * m.value[0][1] + iso->z * m.value[0][2] + m.value[0][3]);
		iso->y = (int) (iso->x * m.value[1][0] + iso->y * m.value[1][1] + iso->z * m.value[1][2] + m.value[1][3]);
		iso->z = (int) (iso->x * m.value[2][0] + iso->y * m.value[2][2] + iso->z * m.value[2][2] + m.value[2][3]);
}
void	rotation_z(t_mlx *map, t_iso *iso)
{
		t_matrix m;

		m = rotation_z_matrix(map);

		iso->x = (int) (iso->x * m.value[0][0] + iso->y * m.value[0][1] + iso->z * m.value[0][2] + m.value[0][3]);
		iso->y = (int) (iso->x * m.value[1][0] + iso->y * m.value[1][1] + iso->z * m.value[1][2] + m.value[1][3]);
		iso->z = (int) (iso->x * m.value[2][0] + iso->y * m.value[2][2] + iso->z * m.value[2][2] + m.value[2][3]);
}

void	translation(t_mlx *map, t_iso *iso)
{
	t_matrix m;

	m = translation_matrix(map);

	iso->x = (int) (iso->x * m.value[0][0] + iso->y * m.value[0][1] + iso->z * m.value[0][2] + m.value[0][3]);
	iso->y = (int) (iso->x * m.value[1][0] + iso->y * m.value[1][1] + iso->z * m.value[1][2] + m.value[1][3]);
	iso->z = (int) (iso->x * m.value[2][0] + iso->y * m.value[2][2] + iso->z * m.value[2][2] + m.value[2][3]);

}
