#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	init_image(t_mlx *mlx)
{
	int		byte_per_pixel;

	byte_per_pixel = mlx->img.bits_per_pixel / 8;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
}
void	img_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
		mlx->img.addr[y * (mlx->img.size_line / 4) + x] = color;
	//printf("result is %d\n", y * 19 + x);
}
void	empty(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		mlx->img.addr[i] = 0;
		i++;
	}
}
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
	printf("min is %d, max is %d\n", map->info.max_z, map->info.min_z);
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


void	iso_reduction(t_iso *iso, int x, int y)
{
	iso->x -= x/2;
	iso->y -= y/2;
}

void	iso_augmentation(t_iso *iso, int x, int y)
{
	iso->x -= x/2;
	iso->y -= y/2;
}

void	cart_to_iso(t_mlx *map, t_iso *iso)
{
	int	angle = 30;
	int	i;
	i = 0;
	while (i < map->info.total)
	{
		if (map->vector[i].z != 0)
		{
			altitude_plus(&map->vector[i], map);
		}

	/*	iso[i].x = ((map->vector[i].x * cos(degToRad(angle))
		+ map->vector[i].y * cos(degToRad(angle + 120))
		+ (map->vector[i].z) * cos(degToRad(angle - 120))));

		iso[i].y = ((map->vector[i].x * sin(degToRad(angle))
		+ map->vector[i].y * sin(degToRad(angle + 120))
		+ (map->vector[i].z)* sin(degToRad(angle - 120))));*/

		iso[i].x = map->vector[i].x;
		iso[i].y = map->vector[i].y;
		iso[i].z = map->vector[i].z;

		iso_reduction(&iso[i], map->info.width, map->info.height);
		scale(&iso[i], map->fac.scale);
		rotation_x(map, &iso[i]);
		rotation_y(map, &iso[i]);
		rotation_z(map, &iso[i]);
		iso_augmentation(&iso[i], map->info.width, map->info.height);
		translation(map, &iso[i]);
		i++;
	}
	get_z(map);
	map->fac.altitude = 0;
}

void	draw_line(int x0, int y0, int x1, int y1, int z1, int z2, t_mlx *map)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while(1){
		if(z1 != map->info.max_z || z1 != z2)
		{
			if (z1 > map->info.max_z / 2 && z2 > map->info.max_z / 2 )
				img_put_pixel(map, x0, y0,0x6dd5ed);
			else
				img_put_pixel(map, x0, y0,0x4286f4);
		}
		else
				img_put_pixel(map, x0, y0,0x7F7FD5);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	draw_map(t_mlx *map, int color)
{
	int	i;
	t_iso	*iso;
	i = 0;

	iso = malloc(sizeof(t_iso) * map->info.total) ;
	cart_to_iso(map, iso);
	while (i < map->info.total)
	{
		/*if (map->vector[i].z != 0)
		{
			color = 0xFF0000;
			printf("iso x is %f\niso y is %f\n", iso[i].x, iso[i].y);
		}
		else
			color = 0xFFFFFF;*/
//		printf("=======(i) is %d\n,iso x is %f\n, iso y is %f\n=======", i, iso[i].x, iso[i].y);
		if (i % map->info.width != map->info.width - 1)
		{
				draw_line((int)iso[i].x, (int)iso[i].y, (int)iso[i + 1].x, (int)iso[i + 1].y, (int)map->vector[i].z, (int)map->vector[i + 1].z, map);
		}
		if (map->info.total - i > map->info.width)
		{
			draw_line((int)iso[i].x, (int)iso[i].y, (int)iso[i + map->info.width].x, (int)iso[i + map->info.width].y,map->vector[i].z, (int)map->vector[i + map->info.width].z, map);
		}
//		printf("i is %d, x is %f, y is %f\n, ==z==is %f\n", i, iso[i].x, iso[i].y, map->vector[i].z);
		img_put_pixel(map, iso[i].x, iso[i].y, color);
		i++;
	}
	free(iso);
}

int		my_key_funct(int keycode, t_mlx *map)
{
	printf("key event %d\n", keycode);

	if (keycode == 53)
	{
		printf("you are pressing ESC\n");
		mlx_destroy_window (map->mlx, map->win);
		exit(1);
	}
	if (keycode == 18)
	{
		map->fac.scale++;
	}
	if (keycode == 19)
	{
		map->fac.scale--;
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
	if (keycode == 125)
	{
		map->fac.translation_y += 30;
	}
	if (keycode == 20)
	{
		map->fac.rotation_x += 5;
	}
	if (keycode == 21)
	{
		map->fac.rotation_x -= 5;
	}
	if (keycode == 22)
	{
		map->fac.rotation_y += 5;
	}
	if (keycode == 23)
	{
		map->fac.rotation_y -= 5;
	}
	if (keycode == 12)
	{
		map->fac.rotation_z += 5;
	}
	if (keycode == 13)
	{
		map->fac.rotation_z -= 5;
	}
	if (keycode == 6)
	{
		map->fac.altitude = 1;
	}
	if (keycode == 7)
	{
		map->fac.altitude = 2;
	}
	if (keycode == 50)
	{
		while (map->fac.rotation_y < 360)
		{
			printf("y is %d\n", map->fac.rotation_y);
				map->fac.rotation_y++;
		}
	}
	empty(map);
	draw_map(map, 0x0087CE);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	return (1);
}

int main(int argc, char *argv[])
{
	t_mlx map;
	int fd;
	char *line;
	t_info	info;

	fd = 0;
	line = NULL;
	map.fac.scale = 20;
	if (argc != 2)
	{
		ft_putstr("wrong arguments numbers\n");
		return (-1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		map.vector = parse_file(fd, &line, &info);
		map.info = info;
		free(line);
	}
	close(fd);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1024, 768, "is this shit working?");
	init_image(&map);
	mlx_key_hook(map.win, my_key_funct, &map);
	draw_map(&map, 0x0087CE);
	mlx_string_put(map.mlx, map.win, 100, 100, 0xFF0000, "test");
	mlx_put_image_to_window(map.mlx, map.win, map.img.img_ptr, 0, 0);
	mlx_loop(map.mlx);
	return (0);
}
