/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:52:26 by zyuan             #+#    #+#             */
/*   Updated: 2018/02/09 15:01:23 by butcherz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdio.h>

/* don't forget to handle file errors!*/

/*
1) New variable to return t_vector new_vector *
2) We malloc this variable + 1 from the vector
3) We copy vector to new_vector
4) We append the tab
5) We free vector
6) we return
*/
t_vector	*realloc_and_append_struct(t_vector *vectors, char **tab, int total, int width)
{
	int i;
	t_vector *new_vector;

	i = 0;
	new_vector = malloc(sizeof(t_vector) * (total + 1));
	while (i < total)
	{
		new_vector[i] = vectors[i];
		i++;
	}
	new_vector[i].x = width;
	new_vector[i].z = ft_atoi(tab[width]);
	free(vectors);
	return new_vector;
}

t_vector	*parse_file(int fd, char **line)
{
		char	**tab;
		t_vector	*vector;
		int		height;
		int		width;
		int 	i;

		i = 0;
		height = 0;
		vector = malloc(sizeof(t_vector) * 1);
		while (get_next_line(fd, line) == 1)
		{
			vector[height].y = height;
			tab = ft_strsplit(*line, ' ');

			if (tab)
			{
				width = 0;
				while (tab[width])
				{
					// vector[i].x = width;
					// vector[i].z = ft_atoi(tab[width]);
					vector = realloc_and_append_struct(vector, tab, i, width);
					width++;
					i++;
				}
			}
			height++;
		}

		for (int i = 0; i < 19 * 11; i++)
		{
				printf("%d ", vector[i].z);
				if (i % 19 == 0 && i != 0)
					printf("\n");
		}
	return (vector);
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
