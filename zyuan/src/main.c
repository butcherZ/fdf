#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	map.fac.scale = 1;
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
