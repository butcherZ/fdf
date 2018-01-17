#include "../minilibx/mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2, int color)
{
	int	m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	if (x1 == x2)
	{
		while (y1 < y2)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x1, y1, color);
			y1++;
		}
		printf("y1 is %d\ny2 is %d\n", y1, y2);
		return ;
	}
	for (int x = x1, y = y1; x <= x2; x++)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		slope_error_new += m_new;
		printf("x is %d\ny is %d\n", x , y);
		printf("m_new is %d\n", m_new);
		printf("slope_error_new is %d\n", slope_error_new);
		if(slope_error_new >= 0)
		{
			y++;
			printf("y inside of loop is %d\n", y);
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}

int		main()
{
	t_mlx test;

	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, 500, 500, "just a test window");
	draw_line(&test, 30, 30, 30, 400, 0x0087CEFA);
	mlx_loop(test.mlx);
}
