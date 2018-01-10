#include "../minilibx/mlx.h"
#include "fdf.h"
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
			img_put_pixel(mlx,  x , y, color);
			p = p + 2 * dy;
		}
		x++;
	}
	return (0);
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
		init_image(map);
		drawline(map, 2, 3, 500, 100, 0x0087CEFA);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
	}
	if (keycode == 18)
	{
		draw_map(50, 550, map);
	}
	return (0);
}


int main()
{
	t_mlx map;

	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 700, 700, "is this shit working?");
	mlx_key_hook(map.win, my_key_funct, &map);
	mlx_loop(map.mlx);
}
