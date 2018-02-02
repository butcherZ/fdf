/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:52:26 by zyuan             #+#    #+#             */
/*   Updated: 2018/02/02 20:24:31 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdio.h>

/* don't forget to handle file errors!*/

typedef	struct s_vector
{
		int		x;
		int		y;
		int		z;
}				t_vector;

//char	**realloc_and_append(char **)
char		**my_get_line(int fd, char **line)
{
		char	**tab;
		t_vector	vector[20];
		int		height;
		int		width;

		height = 0;
		while (get_next_line(fd, line) == 1)
		{
			printf("size of line is %zu\n", ft_strlen(*line));
			vector[height].y = height;
		  // printf("y is %d\n", vector[height].y);	
			height++;
			tab = ft_strsplit(*line, ' ');
			if (tab)
			{
				width = 0;
				while (tab[width])
				{
					vector[width].x = width;
					vector[width].z = ft_atoi(tab[width]);
			//		printf("x is %d\n", vector[width].x);
			//		printf("z is %d\n", vector[width].z);
					width++;
				}
			//printf("width is %d\n", width);
			}
		}
	///	printf("height is %d\n", height);
		for (int i = 0; i < height; i++)
		{
			for (int i = 0; i < width; i++)
			{
				printf("%d", vector[i].z);
			}
			printf("\n");
		}
	return (tab);
}

/*void	print_tab(char **str)
{
		if (str)
		{
			int i = 0;

			while (*(str + i))
			{
				printf("%s", *(str + i));
				free(*(str + i));
				i++;
			}
			printf("width is %d\n", i);
			printf("\n");
			free(str);
		}
}*/

int main(int argc, char *argv[])
{
	int		fd;
	char	 *line;
	char	**tab;

	fd = 0;
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
		printf("something\n");
		/*tab = */my_get_line(fd, &line);
//		print_tab(tab);
	}
	free(line);
	close(fd);
	return (0);
}
