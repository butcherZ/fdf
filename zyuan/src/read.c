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
t_vector	*realloc_and_append_struct(t_vector *vectors, char **tab, t_info *info)
{
	int i;
	t_vector *new_vector;

	i = 0;
	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector) * (info->total + 1))))
		return (NULL);
	while (i < info->total)
	{
		new_vector[i] = vectors[i];
		i++;
	}
	new_vector[i].y = info->height;
	new_vector[i].x = info->width;
	new_vector[i].z = ft_atoi(tab[info->width]);
	free(vectors);
	return new_vector;
}

t_vector	*parse_file(int fd, char **line, t_info *info)
{
		char	**tab;
		t_vector	*vector;
	
		info->total = 0;
		info->height = 0;
		if (!(vector = (t_vector *)malloc(sizeof(t_vector) * 1)))
			return (NULL);
		while (get_next_line(fd, line) == 1)
		{
			tab = ft_strsplit(*line, ' ');
			if (tab)
			{
				info->width = 0;
				while (tab[info->width])
				{
					vector = realloc_and_append_struct(vector, tab, info);
					info->width++;
					info->total++;
				}
			}
			info->height++;
		}
	return (vector);
}
