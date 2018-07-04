/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:41:17 by zyuan             #+#    #+#             */
/*   Updated: 2018/06/30 15:05:00 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

void		reset(t_mlx *map)
{
	map->fac.rotation_x = 0;
	map->fac.rotation_y = 0;
	map->fac.rotation_z = 0;
	map->fac.translation_x = 500;
	map->fac.translation_y = 450;
	map->fac.scale = 20;
}

void		print_usage(t_mlx *map)
{
	mlx_string_put(map->mlx, map->win, 30, 60, 0xFFFFFF, "Usage :");
	mlx_string_put(map->mlx, map->win, 45, 90, 0xFFFFFF, "Translate x/y axes");
	mlx_string_put(map->mlx, map->win, 350, 90, 0xFFFFFF, "Arrow keys");
	mlx_string_put(map->mlx, map->win, 45, 120, 0xFFFFFF, "Roate x axis");
	mlx_string_put(map->mlx, map->win, 350, 120, 0xFFFFFF, "Q W");
	mlx_string_put(map->mlx, map->win, 45, 150, 0xFFFFFF, "Roate y axis");
	mlx_string_put(map->mlx, map->win, 350, 150, 0xFFFFFF, "A S");
	mlx_string_put(map->mlx, map->win, 45, 180, 0xFFFFFF, "Roate z axis");
	mlx_string_put(map->mlx, map->win, 350, 180, 0xFFFFFF, "Z X");
	mlx_string_put(map->mlx, map->win, 45, 210, 0xFFFFFF, "Zoom In/Out");
	mlx_string_put(map->mlx, map->win, 350, 210, 0xFFFFFF, "1 2");
	mlx_string_put(map->mlx, map->win, 45, 240, 0xFFFFFF, "Change altitude");
	mlx_string_put(map->mlx, map->win, 350, 240, 0xFFFFFF, "3 4");
	mlx_string_put(map->mlx, map->win, 45, 270, 0xFFFFFF, "Reset map");
	mlx_string_put(map->mlx, map->win, 350, 270, 0xFFFFFF, "`");
	mlx_string_put(map->mlx, map->win, 45, 300, 0xFFFFFF,
			"Active/Stop Animation");
	mlx_string_put(map->mlx, map->win, 350, 300, 0xFFFFFF, "tab");
	mlx_string_put(map->mlx, map->win, 30, 370, 0xFFFFFF, "MAP PATH :");
	mlx_string_put(map->mlx, map->win, 45, 400, 0x74ebd5, map->argv);
}

int			mlx_while(t_mlx *map)
{
	map->index += 1;
	if (map->trigger == 1 && map->index > 200)
	{
		map->index = 0;
		map->fac.rotation_y -= 2;
		if (map->fac.rotation_y <= -360)
			map->fac.rotation_y = 0;
		empty(map);
		draw_map(map);
		mlx_put_image_to_window(map->mlx, map->win,
				map->img.img_ptr, WIN_WIDTH / 4, 0);
	}
	return (0);
}

void		call_everything(t_mlx *map)
{
	map->index = 0;
	map->trigger = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT,
			"is this shit working?");
	print_usage(map);
	init_image(map);
	reset(map);
	mlx_key_hook(map->win, key_down, map);
	mlx_hook(map->win, 2, 0, key_long_press, map);
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win,
			map->img.img_ptr, WIN_WIDTH / 4, 0);
	mlx_loop_hook(map->mlx, mlx_while, map);
	mlx_loop(map->mlx);
}

int			main(int argc, char *argv[])
{
	t_mlx	map;
	t_info	info;

	map.fd = 0;
	map.read_line = (NULL);
	if (argc != 2)
	{
		ft_putstr("wrong arguments numbers\n");
		return (-1);
	}
	if (argc == 2)
	{
		map.fd = open(argv[1], O_RDONLY);
		map.vector = parse_file(map.fd, &(map.read_line), &info);
		map.info = info;
		map.argv = argv[1];
		if (map.fd < 0 || map.info.error == 1)
		{
			ft_putstr("there's nothing to read....\n");
			return (-1);
		}
	}
	close(map.fd);
	call_everything(&map);
	return (0);
}
