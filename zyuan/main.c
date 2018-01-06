#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	void *mlx;
	void *win;
} t_test;

int		my_key_funct(int keycode, t_test *test)
{
		printf("key event %d\n", keycode);
		if (keycode == 53)
		{
			printf("you are pressing ESC\n");
			mlx_destroy_window (test->mlx, test->win);
			exit(1);
		//	for (int i = 0; i < 999; i++)
		//		mlx_pixel_put(test->mlx, test->win, i, 200, 0x0087CEFA);


		}
		if (keycode == 18)
		{
			int repeat = 20;
			mlx_clear_window(test->mlx, test->win);
			while (repeat < 500)
			{
				int x = 0;
				while (x < 500)
				{
					int y = 0;
					while (y < 500)
					{	
						mlx_pixel_put(test->mlx, test->win, repeat, y, 0x0087CEFA);
						y++;
					}
					mlx_pixel_put(test->mlx, test->win, x, repeat, 0x0087CEFA);
					x++;
				}
				repeat = repeat + 20;
			}
		}	
			return (0);
}

int main()
{
	t_test test;
	int		x;
	int		y;

	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, 500, 500, "is this shit working?");
	y = 50;
	while (y < 200)
	{
		x = 50;
		while (x < 200)
		{
			mlx_pixel_put(test.mlx, test.win, x, y, 0x00FFD700);
			x++;
		}
		y++;
	}
	mlx_key_hook(test.win, my_key_funct, &test);
	mlx_loop(test.mlx);
}
