#include "../minilibx/mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	draw_image(t_mlx *mlx, int x, int y, int color)
{
	int	 byte_per_pixel;
	int		i;	
	int	 	count_h;
	int		count_w;
	
	i = 0;
	byte_per_pixel = mlx->img.bits_per_pixel / 8;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, x, y);
	mlx->img.addr = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);/*init imgae*/

	printf("byte_per_pixel is %d, bits_per_pixel is %d, size_line is %d\n", byte_per_pixel, mlx->img.bits_per_pixel, mlx->img.size_line);
	
	count_h = -1;
	while (count_h < WIN_HEIGHT)
	{
		count_w = -1;
		if (count_h / mlx->img.size_line)
			mlx->img.addr[count_h * WIN_WIDTH + count_w] = 0x009370DB;
		while (count_w < WIN_WIDTH)
		{
			if (count_w % (mlx->img.size_line))
				mlx->img.addr[count_h * WIN_WIDTH + count_w] = 0x00FFFFFF;
					count_w += 50;
		}
		count_h += 50;
	}
	/*while (i < x * y * byte_per_pixel)
	  {
	  int j = 0;
	  while (j < x * byte_per_pixel)
	  {
	  memcpy(mlx->img.addr + j, &color, byte_per_pixel);
	  j = j + byte_per_pixel; //print horizontal line
	  }
	  memcpy(mlx->img.addr + i, &color, byte_per_pixel);
	  i = i + mlx->img.size_line; //print vertical line
	  }*/
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
		draw_image(map, WIN_WIDTH, WIN_HEIGHT, 0x0087CEFA);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 0, 0);
		//	mlx_clear_window(test->mlx, test->win);
		//	mlx_string_put(test->mlx, test->win, 100, 100, 0x00FFFFFF, "hello, asshole");
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
