#include "../minilibx/mlx.h"
#include <stdio.h>

int		my_key_funct(int keycode, void *mlx)
{
		printf("key event %d\n", keycode);
		if (keycode == 53)
		{
			printf("you are pressing ESC\n");
			//mlx_pixel_put(mlx, win, 200, 200, 0x0087CEFA);

		}
		return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "is this shit working?");
	y = 50;
	while (y < 800)
	{
		x = 50;
		while (x < 800)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFD700);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_funct, mlx);	
	mlx_loop(mlx);	
}
