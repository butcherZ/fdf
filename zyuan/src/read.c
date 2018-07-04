/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:52:26 by zyuan             #+#    #+#             */
/*   Updated: 2018/07/04 18:13:32 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

t_vector	*realloc_and_append_struct(t_vector *vectors, char **tab,
		t_info *info)
{
	int			i;
	t_vector	*new_vector;

	i = 0;
	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector) *
					(info->total + 1))))
		return (NULL);
	while (i < info->total)
	{
		new_vector[i] = vectors[i];
		i++;
	}
	new_vector[i].y = (double)info->height;
	new_vector[i].x = (double)info->width;
	new_vector[i].z = (double)ft_atoi(tab[info->width]);
	free(vectors);
	return (new_vector);
}

void		initiate_info(t_info *info)
{
	info->total = 0;
	info->height = 0;
	info->error = 1;
}

t_vector	*parse_file(int fd, char **line, t_info *info)
{
	char		**tab;
	t_vector	*vector;

	initiate_info(info);
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
		check_format_errors(info);
		free_everything(line, tab, info);
	}
	check_content_erros(info);
	return (vector);
}
