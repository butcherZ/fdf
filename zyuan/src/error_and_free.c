/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:12:14 by zyuan             #+#    #+#             */
/*   Updated: 2018/07/04 18:12:32 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

void		free_tab(char **tab, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->width + 1)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		free_everything(char **line, char **tab, t_info *info)
{
	info->error = 0;
	free_tab(tab, info);
	free(*line);
}

void		check_content_erros(t_info *info)
{
	if (info->total >= 250000)
	{
		ft_putstr("file is too big");
		exit(1);
	}
}

void		check_nazi(t_mlx *map)
{
	char *str1;
	char *str2;

	str1 = "/dev/random";
	str2 = "/dev/urandom";
	if (ft_strcmp(map->argv, str1) == 0 || ft_strcmp(map->argv, str2) == 0)
	{
		ft_putstr("NAZI ALERT!!!");
		exit(1);
	}
}

void		check_format_errors(t_info *info)
{
	if (info->total / info->height != info->width)
	{
		ft_putstr("not correct format");
		info->error = 1;
		exit(1);
	}
}
