#include "../minilibx/mlx.h"
#include <stdio.h>

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
		return (0);
}

int main()
{
	t_test test;
	int		x;
	int		y;

	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, 1000, 1000, "is this shit working?");
	y = 50;
	while (y < 800)
	{
		x = 50;
		while (x < 800)
		{
			mlx_pixel_put(test.mlx, test.win, x, y, 0x00FFD700);
			x++;
		}
		y++;
	}
	mlx_key_hook(test.win, my_key_funct, &test);
	mlx_loop(test.mlx);
}
