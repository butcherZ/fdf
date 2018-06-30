/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:07:49 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/30 12:22:59 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		print_key_usage(int keycode)
{
	ft_putstr("you are pressing key ");
	ft_putnbr(keycode);
	ft_putchar('\n');
}

void		key_rotation(int keycode, t_mlx *map)
{
	if (keycode == 12)
	{
		map->fac.rotation_x += 5;
	}
	if (keycode == 13)
	{
		map->fac.rotation_x -= 5;
	}
	if (keycode == 0)
	{
		map->fac.rotation_y += 5;
	}
	if (keycode == 1)
	{
		map->fac.rotation_y -= 5;
	}
	if (keycode == 6)
	{
		map->fac.rotation_z += 5;
	}
	if (keycode == 7)
	{
		map->fac.rotation_z -= 5;
	}
}

void		key_translation(int keycode, t_mlx *map)
{
	if (keycode == 125)
	{
		map->fac.translation_y += 30;
	}
	if (keycode == 124)
	{
		map->fac.translation_x += 30;
	}
	if (keycode == 123)
	{
		map->fac.translation_x -= 30;
	}
	if (keycode == 126)
	{
		map->fac.translation_y -= 30;
	}
}

int			key_long_press(int keycode, t_mlx *map)
{
	print_key_usage(keycode);
	if (keycode == 18)
		map->fac.scale++;
	if (keycode == 19)
	{
		map->fac.scale--;
		if (map->fac.scale < 1)
			map->fac.scale = 1;
	}
	if (keycode == 20)
		map->fac.altitude = 1;
	if (keycode == 21)
		map->fac.altitude = 2;
	key_translation(keycode, map);
	key_rotation(keycode, map);
	empty(map);
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win,
			map->img.img_ptr, WIN_WIDTH / 4, 0);
	return (1);
}

int			key_down(int keycode, t_mlx *map)
{
	print_key_usage(keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(1);
	}
	if (keycode == 50)
	{
		reset(map);
	}
	if (keycode == 48)
	{
		map->trigger = (map->trigger + 1) % 2;
	}
	empty(map);
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win,
			map->img.img_ptr, WIN_WIDTH / 4, 0);
	return (1);
}
