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

/* don't forget to handle file errors!
And color hexadecimal
*/
t_vector	*realloc_and_append_struct(t_vector *vectors, char **tab, int total, int width, int height)
{
	int i;
	t_vector *new_vector;

	i = 0;
	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector) * (total + 1))))
		return (NULL);
	while (i < total)
	{
		new_vector[i] = vectors[i];
		i++;
	}
	new_vector[i].y = height;
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
		if (!(vector = (t_vector *)malloc(sizeof(t_vector) * 1)))
			return (NULL);
		while (get_next_line(fd, line) == 1)
		{
			tab = ft_strsplit(*line, ' ');
			if (tab)
			{
				width = 0;
				while (tab[width])
				{
					vector = realloc_and_append_struct(vector, tab, i, width, height);
					width++;
					i++;
				}
			}
			height++;
		}
	return (vector);
}
