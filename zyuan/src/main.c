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
	iso->z = map->vector[i].z;
	printf("isox is %d\n, isoy is %d\n", iso->x, iso->y);
*/
	return (iso);
}

void	scale(t_iso *iso, int factor)
{
	iso->x = iso->x * factor;
	iso->y = iso->y * factor;
}
void	draw_map(t_mlx *map, int color, int scale_fac)
{
	int	i;
	t_iso	*iso;
	i = 0;

	//printf("total is %d\n", map->info.total);
	while (i < map->info.total)
	{
		iso = cart_to_iso(map, i);
		if (map->vector[i].z != 0)
			color = 0xFF0000;
		else
			color = 0xFFFFFF;
		scale(iso, scale_fac);
		img_put_pixel(map, iso->x + 500, iso->y + 300, color);
//		img_put_pixel(map, map->vector[i].x, map->vector[i].y, color);
		i++;
	}
}
void	draw_heart(t_mlx *map, int color)
{
	int plus = map->info.width;
	while (plus < WIN_WIDTH)
	{
		int i = 0;
		while (i < map->info.total)
		{
			if (map->vector[i].z != 0)
				color = 0xFF0000;
			else
				color = 0x000000;
			img_put_pixel(map, map->vector[i].x, map->vector[i].y, color);
			img_put_pixel(map, map->vector[i].x, map->vector[i].y + 150, color);
			img_put_pixel(map, map->vector[i].x + plus, map->vector[i].y, color);
			img_put_pixel(map, map->vector[i].x + plus, map->vector[i].y + 150, color);
			
			i++;
		}
		plus = plus + map->info.width;
	}
}
int		my_key_funct(int keycode, t_mlx *map)
{
//	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		printf("you are pressing ESC\n");
		mlx_destroy_window (map->mlx, map->win);
		exit(1);
	}
	if (keycode == 18)
	{
		mlx_clear_window(map->mlx, map->win);
		init_image(map);
		draw_map(map,  0x0087CE, 5);
		draw_heart(map, 0x0087CE);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	if (keycode == 19)
	{
		mlx_clear_window(map->mlx, map->win);
		init_image(map);
		draw_map(map,  0x0087CE, ++map->size_scale);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	if (keycode == 20)
	{
		init_image(map);
		mlx_clear_window(map->mlx, map->win);
		draw_map(map,  0x0087CE, --map->size_scale);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	if (keycode == 21)
	{
		init_image(map);
		mlx_string_put(map->mlx, map->win, 150, 80, 0xFF0000, "Happy Valentine's day everyone, Here's a buggy heart in its isometric view");
	}
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
	map.size_scale = 1;
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
		/*	for (int i = 0; i <= 19 * 3; i++)
			{
			printf("x is %d y is %d z is %d\n", map.vector[i].x, map.vector[i].y, map.vector[i].z);
			}*/
	}
	close(fd);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1024, 768, "is this shit working?");
	mlx_key_hook(map.win, my_key_funct, &map);
	mlx_loop(map.mlx);
	return (0);
}
