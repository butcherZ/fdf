#include "fdf.h"

void	horizontalright(t_mlx *map, t_iso first, t_iso second, int color)
{
	int x;

	x = first.x;
	while (x < second.x)
	{
		img_put_pixel(map, x, first.y, color);
		x++;
	}
}

void	horizontalleft(t_mlx *map, t_iso first, t_iso second, int color)
{
	int x;

	x = first.x;
	while (x > second.x)
	{
		img_put_pixel(map, x, first.y, color);
		x--;
	}
}

void	brasenham2(t_mlx *map, t_iso first, t_iso second, int color)
{
	int dx;
	int dy;

	dx = second.x - first.x;
	dy = second.y - first.y;
	if ((dx < 0) && (dy > 0))
	{
		if ((dx * -1) >= dy)
			fourtho(map, first, second, color);
		else
			thirdo(map, first, second, color);
	}
	if ((dx < 0) && (dy < 0))
	{
		if (dx <= dy)
			fiftho(map, first, second, color);
		else
			sixtho(map, first, second, color);
	}
	if ((dx < 0) && (dy == 0))
		horizontalleft(map, first, second, color);
	if ((dx == 0) && (dy > 0))
		verticaldown(map, first, second, color);
	if ((dx == 0) && (dy < 0))
		verticalup(map, first, second, color);
}

void	brasenham(t_mlx *map, t_iso first, t_iso second, int color)
{
	int dx;
	int dy;

	dx = second.x - first.x;
	dy = second.y - first.y;
	if ((dx > 0) && (dy > 0))
	{
		if (dx >= dy)
			firsto(map, first, second, color);
		else
			secondo(map, first, second, color);
	}
	if ((dx > 0) && (dy < 0))
	{
		if (dx >= (-1 * dy))
			eighto(map, first, second, color);
		else
			seveno(map, first, second, color);
	}
	if ((dx > 0) && (dy == 0))
		horizontalright(map, first, second, color);
	if (dx <= 0)
		brasenham2(map, first, second, color);
}

void	firsto(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x < second.x)
	{
		img_put_pixel(map, x, y, color);
		e = e - dy;
		if (e < 0)
		{
			y++;
			e = e + dx;
		}
		x++;
	}
}

void	secondo(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y < second.y)
	{
		img_put_pixel(map, x, y, color);
		e = e - dx;
		if (e < 0)
		{
			x++;
			e = e + dy;
		}
		y++;
	}
}

void	thirdo(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y < second.y)
	{
		img_put_pixel(map, x, y, color);
		e = e + dx;
		if (e <= 0)
		{
			x--;
			e = e + dy;
		}
		y++;
	}
}

void	fourtho(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x > second.x)
	{
		img_put_pixel(map, x, y, color);
		e = e + dy;
		if (e >= 0)
		{
			y++;
			e = e + dx;
		}
		x--;
	}
}

void	fiftho(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x > second.x)
	{
		img_put_pixel(map, x, y, color);
		e = e - dy;
		if (e >= 0)
		{
			y--;
			e = e + dx;
		}
		x--;
	}
}

void	sixtho(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y > second.y)
	{
		img_put_pixel(map, x, y, color);
		e = e - dx;
		if (e >= 0)
		{
			x--;
			e = e + dy;
		}
		y--;
	}
}

void	seveno(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y > second.y)
	{
		img_put_pixel(map, x, y, color);
		e = e + dx;
		if (e > 0)
		{
			x++;
			e = e + dy;
		}
		y--;
	}
}

void	eighto(t_mlx *map, t_iso first, t_iso second, int color)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x < second.x)
	{
		img_put_pixel(map, x, y, color);
		e = e + dy;
		if (e < 0)
		{
			y--;
			e = e + dx;
		}
		x++;
	}
}

void	verticaldown(t_mlx *map, t_iso first, t_iso second, int color)
{
	int y;

	y = first.y;
	while (y < second.y)
	{
		img_put_pixel(map, first.x, y, color);
		y++;
	}
}

void	verticalup(t_mlx *map, t_iso first, t_iso second, int color)
{
	int y;

	y = first.y;
	while (y > second.y)
	{
		img_put_pixel(map, first.x, y, color);
		y--;
	}
}
