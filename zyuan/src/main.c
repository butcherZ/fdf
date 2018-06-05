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

t_iso	*cart_to_iso(t_mlx *map, int i)
{
	t_iso	*iso;

	int	angle = 30;
	iso = malloc(sizeof(t_iso) * map->info.total);
	iso->x = (map->vector[i].x * cos(degToRad(angle))
			+ map->vector[i].y * cos(degToRad(angle + 120))
			+ map->vector[i].z * cos(degToRad(angle - 120)));
	iso->y = (map->vector[i].x * sin(degToRad(angle))
			+ map->vector[i].y * sin(degToRad(angle + 120))
			+ map->vector[i].z * sin(degToRad(angle - 120)));
	/*	iso->x = (map->vector[i].x - map->vector[i].y);
		iso->y = (map->vector[i].x + map->vector[i].y) / 2;
		iso->z = map->vector[i].z;*/
	 
	return (iso);
}

void	scale(t_iso *iso, int factor)
{
	iso->x = iso->x * factor;
	iso->y = iso->y * factor;
}

void	translation_x(t_iso *iso, int factor)
{
	iso->x = iso->x + factor;
}

void	translation_y(t_iso *iso, int factor)
{
	iso->y = iso->y + factor;
}
void	draw_line(t_mlx *mlx,int x0, int x1, int y0, int y1, int color)
{
	int	dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x < x1)
	{
		if (p >= 0)
		{
			img_put_pixel(mlx, x, y, color);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			img_put_pixel(mlx, x, y, color);
			p = p + 2 * dy;
		}
		x++;
	}
}


void	draw_map(t_mlx *map, int color)
{
	int	i;
	t_iso	*iso;
	i = 0;

	printf("total is %d\n", map->info.total);
	while (i < map->info.total)
	{
		iso = cart_to_iso(map, i);
		if (map->vector[i].z != 0)
			color = 0xFF0000;
		else
			color = 0xFFFFFF;
		scale(iso, map->fac.scale);
		translation_x(iso, map->fac.translation_x);
		translation_y(iso, map->fac.translation_y);
	
//		printf("isox is %d\n, isoy is %d\n", iso->x, iso->y);
	//draw_line(map, iso->x + 500, iso->x + 500 + i, iso->y + 300, iso->y +300 + i, 0x0087CE);
		brasenham(map, *iso, *(iso + 1), 0x0087CE);
		img_put_pixel(map, iso->x, iso->y, color);
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
		map->fac.translation_x += 5;
	}
	if (keycode == 123)
	{
		map->fac.translation_x -= 5;
	}
	if (keycode == 125)
	{
		map->fac.translation_y -= 5;
	}
	if (keycode == 126)
	{
		map->fac.translation_y += 5;
	}
	empty(map);
	draw_map(map, 0x0087CE);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	return (0);
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
	mlx_key_hook(map.win, my_key_funct, &map);
	init_image(&map);
	draw_map(&map, 0x0087CE);
	mlx_put_image_to_window(map.mlx, map.win, map.img.img_ptr, 0, 0);
	mlx_loop(map.mlx);
	return (0);
}
