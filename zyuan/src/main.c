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
	mlx->img.addr[y * WIN_WIDTH + x] = color;
}

int drawline(t_mlx *mlx, int x0, int y0, int x1, int  y1, int color)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * (dy - dx);
	if (x0 == x1)
	{
		while (y0 < y1)
		{
			img_put_pixel(mlx, x0, y0, color);
			y0++;
		}
	}
	while(x < x1)
	{
		if ( p >= 0)
		{	
			img_put_pixel(mlx, x, y, color);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			img_put_pixel(mlx, x , y, color);
			p = p + 2 * dy;
		}
		x++;
	}
	return (0);
}

void	draw_image(t_mlx *mlx, int gap, int x0, int y0, int x1, int y1, int color)
{
	/*		while (y0 <= WIN_HEIGHT)
			{
			drawline(mlx, x0, y0, x1, y1, color);
			y0 = y0 + gap;
			y1 = y1 + gap;
			}*/
	int i = 0;

	while (x0 < WIN_WIDTH)
	{
		drawline(mlx, x0, y0, x1, y1, color);
		//		if (x0 < y0)
		//		{	
		drawline(mlx, y0, x0, y1, x1, color);
		//		}
		printf("======  %d  =====\nx0 is %d\ny0 is %d\nx1 is %d\ny1 is %d\n=====",i, x0, y0, x1, y1);
		x0 = x0 + gap;
		x1 = x1 + gap;
		i++;
	}
}
void	draw_map(int repeat, int screen_size, t_mlx *map)
{
	mlx_clear_window(map->mlx, map->win);
	while (repeat <= screen_size)
	{
		map->x = 50;
		map->y = 50;
		while (map->x < screen_size)
		{
			mlx_pixel_put(map->mlx, map->win, repeat, map->y, 0x0087CEFA);
			mlx_pixel_put(map->mlx, map->win, map->x, repeat, 0x009370DB);
			map->x++;
			map->y++;
		}
		repeat = repeat + 50;
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
	if (keycode == 19)
	{
		mlx_clear_window(map->mlx, map->win);
		init_image(map);
		//		drawline(map, 100, 20, 200, 20, 0x0087CEFA);
		//		drawline(map, 20, 100, 20, 200, 0x0087CEFA);
		//	draw_image(map, 50, 100, 20, 500, 20, 0x0087CEFA);
		draw_image(map, 50, 20, 100, 20, 500, 0x0087CEFA);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	if (keycode == 18)
	{
		draw_map(50, 550, map);
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
		parse_file(fd, &line);
	}
	free(line);
	close(fd);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 700, 700, "is this shit working?");
	mlx_key_hook(map.win, my_key_funct, &map);
	mlx_loop(map.mlx);
	return (0);
}
