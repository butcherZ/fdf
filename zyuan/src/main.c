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
	mlx->img.addr[y * (mlx->img.size_line / 4) + x] = color;
	//printf("result is %d\n", y * 19 + x);
}
t_iso	*cart_to_iso(t_mlx *map, int i)
{
	t_iso	*iso;

	iso = malloc(sizeof(t_iso) * map->info.total);
	
	iso->x = (map->vector[i].x - map->vector[i].y);
	iso->y = (map->vector[i].x + map->vector[i].y) / 2;
	iso->z = map->vector[i].z;
	printf("isox is %d\n, isoy is %d\n", iso->x, iso->y);

	
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
		//isox = (map->vector[i].x - map->vector[i].y);
		//isoy = (map->vector[i].x + map->vector[i].y) / 2;
		if (map->vector[i].z != 0)
			color = 0xFFFFFF;
		else
			color = 0xFF0000;
			scale(iso, scale_fac);
			img_put_pixel(map, iso->x + 100, iso->y + 100, color);
		i++;	
	}
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
		mlx_clear_window(map->mlx, map->win);
		init_image(map);
		draw_map(map,  0x0087CE, 10);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
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
	 map.win = mlx_new_window(map.mlx, 700, 700, "is this shit working?");
	 mlx_key_hook(map.win, my_key_funct, &map);
	 mlx_loop(map.mlx);
	return (0);
}
