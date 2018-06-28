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
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	mlx->img.addr = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
}
void	img_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if((x > 0 && x < IMG_WIDTH) && (y > 0 && y < IMG_HEIGHT))
		mlx->img.addr[y * (mlx->img.size_line / 4) + x] = color;
	//printf("result is %d\n", y * 19 + x);
}
void	empty(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < IMG_HEIGHT * IMG_WIDTH)
	{
		mlx->img.addr[i] = 0;
		i++;
	}
}
void	get_z(t_mlx *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->info.max_z = map->vector[0].z;
	map->info.min_z = map->vector[0].z;
	while (i < map->info.total && j < map->info.total)
	{
		if (map->vector[i].z < map->info.max_z)
		{
			map->info.max_z = map->vector[i].z;
		}
		if (map->vector[j].z > map->info.min_z)
		{
			map->info.min_z = map->vector[j].z;
		}
		i++;
		j++;
	}
	map->info.range_z = abs(map->info.max_z - map->info.min_z);
	//printf("min is %d, max is %d\n range is %d\n", map->info.max_z, map->info.min_z, map->info.range_z);
}

void	altitude_plus(t_vector *vec, t_mlx *map)
{
	if (map->fac.altitude == 1)
		vec->z += 1;
	if (map->fac.altitude == 2)
		vec->z -= 1;
	if (map->fac.altitude == 2 && vec->z == 0)
		vec->z = -1;
	if (map->fac.altitude == 1 && vec->z == 0)
		vec->z = 1;
	printf("altitude is %f\n", vec->z);
}


void	iso_reduction(t_iso *iso, int x, int y)
{
	iso->x -= x/2;
	iso->y -= y/2;
}

void	iso_augmentation(t_iso *iso, int x, int y)
{
	iso->x -= x/2;
	iso->y -= y/2;
}

void	cart_to_iso(t_mlx *map, t_iso *iso)
{
	int	angle = 30;
	int	i;
	i = 0;
	while (i < map->info.total)
	{
		if (map->vector[i].z != 0)
		{
			altitude_plus(&map->vector[i], map);
		}

		/*iso[i].x = ((map->vector[i].x * cos(degToRad(angle))
		+ map->vector[i].y * cos(degToRad(angle + 120))
		+ (map->vector[i].z) * cos(degToRad(angle - 120))));

		iso[i].y = ((map->vector[i].x * sin(degToRad(angle))
		+ map->vector[i].y * sin(degToRad(angle + 120))
		+ (map->vector[i].z)* sin(degToRad(angle - 120))));*/

		iso[i].x = map->vector[i].x;
		iso[i].y = map->vector[i].y;
		iso[i].z = map->vector[i].z;

		iso_reduction(&iso[i], map->info.width, map->info.height);
		scale(&iso[i], map->fac.scale);
		rotation_x(map, &iso[i]);
		rotation_y(map, &iso[i]);
		rotation_z(map, &iso[i]);
		iso_augmentation(&iso[i], map->info.width, map->info.height);
		translation(map, &iso[i]);
		i++;
	}
	get_z(map);
	map->fac.altitude = 0;
}

void	draw_line(t_vector *vect0, t_vector *vect1, t_mlx *map)
{
	int dx = abs(vect1->x - vect0->x), sx = vect0->x < vect1->x ? 1 : -1;
	int dy = abs(vect1->y - vect0->y), sy = vect0->y < vect1->y ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while(1){

	/*	if (vect0-> z >= 0 && vect0->z <= 3 && vect1-> z >= 0 && vect1->z <= 3)
			img_put_pixel(map, vect0->x, vect0->y, 0x6dd5ed);
		if (vect0-> z >= 3 && vect0->z <= 5 && vect1-> z >= 3 && vect1->z <= 5)
			img_put_pixel(map, vect0->x, vect0->y, 0x4286f4);
		if (vect0-> z >= 6 && vect0->z <= 8 && vect1-> z >= 6 && vect1->z <= 8)
			img_put_pixel(map, vect0->x, vect0->y, 0x7F7FD5);
		else
			img_put_pixel(map, vect0->x, vect0->y, 0xFFFFFF);*/
		if(vect0->z != map->info.max_z || vect0->z != vect1->z)
		{
			if (vect0->z > map->info.max_z / 2 && vect1->z > map->info.max_z / 2)
			{
				img_put_pixel(map, vect0->x, vect0->y, 0x6dd5ed); //top
			}
			else
				img_put_pixel(map, vect0->x, vect0->y, 0x4286f4); //blue, z
		}
		else
				img_put_pixel(map, vect0->x, vect0->y, 0x7F7FD5); //purple
		if (vect0->x == vect1->x && vect0->y == vect1->y) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; vect0->x += sx; }
		if (e2 < dy) { err += dx; vect0->y += sy; }
	}
}

t_vector new_vector(int x, int y, int z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}

void	draw_map(t_mlx *map)
{
	int	i;
	t_iso	*iso;
	t_vector vect0;
	t_vector vect1;
	i = 0;

	iso = malloc(sizeof(t_iso) * map->info.total) ;
	cart_to_iso(map, iso);
	while (i < map->info.total)
	{
		/*if (map->vector[i].z != 0)
		{
			color = 0xFF0000;
			printf("iso x is %f\niso y is %f\n", iso[i].x, iso[i].y);
		}
		else
			color = 0xFFFFFF;*/
//		printf("=======(i) is %d\n,iso x is %f\n, iso y is %f\n=======", i, iso[i].x, iso[i].y);
		if (i % map->info.width != map->info.width - 1)
		{
				vect0 = new_vector((int)iso[i].x, (int)iso[i].y, (int)map->vector[i].z);
				vect1 = new_vector( (int)iso[i + 1].x, (int)iso[i + 1].y, (int)map->vector[i + 1].z);
				draw_line(&vect0, &vect1, map);
		}
		if (map->info.total - i > map->info.width)
		{
				vect0 = new_vector((int)iso[i].x, (int)iso[i].y, map->vector[i].z);
				vect1 = new_vector( (int)iso[i + map->info.width].x, (int)iso[i + map->info.width].y, (int)map->vector[i + map->info.width].z);
				draw_line(&vect0, &vect1, map);
		}
	//	printf("i is %d, x is %f, y is %f\n, ==z==is %f\n", i, iso[i].x, iso[i].y, iso[i].z);
		i++;
	}
	free(iso);
}
void 	reset(t_mlx *map)
{
		map->fac.rotation_x = 0;
		map->fac.rotation_y = 0;
		map->fac.rotation_z = 0;
		map->fac.translation_x = 500;
		map->fac.translation_y = 450;
		map->fac.scale = 20;
}

void usage(t_mlx *map)
{
		mlx_string_put(map->mlx, map->win, 30, 60, 0xFFFFFF, "Usage :");
		mlx_string_put(map->mlx, map->win, 45, 90, 0xFFFFFF, "Translate x/y axes");
		mlx_string_put(map->mlx, map->win, 350, 90, 0xFFFFFF, "Arrow keys");
		mlx_string_put(map->mlx, map->win, 45, 120, 0xFFFFFF, "Roate x axis");
		mlx_string_put(map->mlx, map->win, 350, 120, 0xFFFFFF, "Q W");
		mlx_string_put(map->mlx, map->win, 45, 150, 0xFFFFFF, "Roate y axis");
		mlx_string_put(map->mlx, map->win, 350, 150, 0xFFFFFF, "A S");
		mlx_string_put(map->mlx, map->win, 45, 180, 0xFFFFFF, "Roate z axis");
		mlx_string_put(map->mlx, map->win, 350, 180, 0xFFFFFF, "Z X");
		mlx_string_put(map->mlx, map->win, 45, 210, 0xFFFFFF, "Zoom In/Out");
		mlx_string_put(map->mlx, map->win, 350, 210, 0xFFFFFF, "1 2");
		mlx_string_put(map->mlx, map->win, 45, 240, 0xFFFFFF, "Change altitude");
		mlx_string_put(map->mlx, map->win, 350, 240, 0xFFFFFF, "3 4");
		mlx_string_put(map->mlx, map->win, 45, 270, 0xFFFFFF, "Reset map");
		mlx_string_put(map->mlx, map->win, 350, 270, 0xFFFFFF, "`");
		mlx_string_put(map->mlx, map->win, 45, 300, 0xFFFFFF, "Active/Stop Animation");
		mlx_string_put(map->mlx, map->win, 350, 300, 0xFFFFFF, "tab");
		mlx_string_put(map->mlx, map->win, 30, 370, 0xFFFFFF, "MAP PATH :");
		mlx_string_put(map->mlx, map->win, 45, 400, 0x74ebd5, map->argv);
}

int mlx_while(t_mlx *map)
{
//	ft_putstr("test\n");
	map->index += 1;
//	printf("%d\n", map->index);
	if (map->trigger == 1 && map->index > 200)
	{
			map->index = 0;
			map->fac.rotation_y -= 2;
			if (map->fac.rotation_y <= -360)
				map->fac.rotation_y = 0;
			//sleep(0.1);
			empty(map);
			draw_map(map);
			mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, WIN_WIDTH/4, 0);

		printf("y is %d\n", map->fac.rotation_y);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_mlx map;
	int fd;
	char *line;
	t_info	info;

	fd = 0;
	line = NULL;
	map.fac.scale = 20;
	map.index = 0;
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
		map.vector = parse_file(fd, &line, &info);
		map.info = info;
		map.argv = argv[1];
		//free(line);
	}
	map.trigger = 0;
	close(fd);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "is this shit working?");
	usage(&map);
	init_image(&map);
	mlx_key_hook(map.win, key_down, &map);
	mlx_hook(map.win, 2, 0, key_long_press, &map);
	draw_map(&map);
	mlx_put_image_to_window(map.mlx, map.win, map.img.img_ptr, WIN_WIDTH/4, 0);
	mlx_loop_hook(map.mlx, mlx_while, &map);
	mlx_loop(map.mlx);
	return (0);
}
