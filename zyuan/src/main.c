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
	printf("result is %d\n", y * 19 + x);
}

void	draw_map(t_mlx *map, int color)
{		
		for (int i = 0; i < 19 * 11; i++)
		{
			if (map->vector[i].z != 0)
				color = 0xFFFFFF;
			else
				color = 0xFF0000;
			img_put_pixel(map, map->vector[i].x, map->vector[i].y, color);
			
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
		draw_map(map,  0x0087CE);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	return (0);
}


int main(int argc, char *argv[])
{
	 t_mlx map;
	int fd;
	char *line;

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
		map.vector = parse_file(fd, &line);

		free(line);
		for (int i = 0; i <= 19 * 3; i++)
		{
			printf("x is %d y is %d z is %d\n", map.vector[i].x, map.vector[i].y, map.vector[i].z);
		}
	}
	 close(fd);
	 map.mlx = mlx_init();
	 map.win = mlx_new_window(map.mlx, 700, 700, "is this shit working?");
	 mlx_key_hook(map.win, my_key_funct, &map);
	 mlx_loop(map.mlx);
	return (0);
}
