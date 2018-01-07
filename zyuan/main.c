#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	void 	*mlx;
	void 	*win;
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
	int		x;
	int		y;

} 			t_test;

void	init_image(t_test *test)
{
			test->img = mlx_new_image(test->mlx, 500, 500);
			printf("1\n");
			test->addr = mlx_get_data_addr(test->img, &test->bits_per_pixel, &test->size_line, &test->endian);
			printf("111\n");
			printf("addr is %s\n", test->addr);

}

void	draw_map(int repeat, int screen_size, t_test *test)
{
		mlx_clear_window(test->mlx, test->win);
		while (repeat <= screen_size)
		{
			test->x = 50;
			test->y = 50;
			while (test->x < screen_size)
			{	
				mlx_pixel_put(test->mlx, test->win, repeat, test->y, 0x0087CEFA);
				mlx_pixel_put(test->mlx, test->win, test->x, repeat, 0x009370DB);
				test->x++;
				test->y++;
			}
			repeat = repeat + 50;
		}

}
int		my_key_funct(int keycode, t_test *test)
{

		printf("key event %d\n", keycode);
		if (keycode == 53)
		{
			printf("you are pressing ESC\n");
			mlx_destroy_window (test->mlx, test->win);
			exit(1);
		}
		if (keycode == 19)
		{
			init_image(test);
			mlx_clear_window(test->mlx, test->win);
			mlx_string_put(test->mlx, test->win, 100, 100, 0x00FFFFFF, "hello, asshole");
		}
		if (keycode == 18)
		{
			draw_map(50, 550, test);
		}	
			return (0);
}


int main()
{
	t_test test;
//	int		x;
//	int		y;

	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, 700, 700, "is this shit working?");
//	y = 50;
/*	while (y < 200)
	{
		x = 50;
		while (x < 200)
		{
			mlx_pixel_put(test.mlx, test.win, x, y, 0x00FFD700);
			x++;
		}
		y++;
	}*/
	mlx_key_hook(test.win, my_key_funct, &test);
	mlx_loop(test.mlx);
}
