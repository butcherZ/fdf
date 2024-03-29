/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 03:20:56 by zyuan             #+#    #+#             */
/*   Updated: 2018/07/14 17:30:23 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <string.h>

void		check_letter(char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i] == '+' || tab[i] == '-') && i == 0)
			i++;
		if (ft_isdigit(tab[i]) == 0)
			tab[i] = 1;
		if (ft_atoi(&tab[i]) >= 1000)
		{
			ft_putstr("Are you high? cause I am...x)");
			exit(1);
		}
		i++;
	}
}

void		check_content_errors(t_info *info)
{
	if (info->total >= 250000)
	{
		ft_putstr("file is too big");
		exit(1);
	}
}

void		check_nazi(t_mlx *map)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "/dev/random";
	str2 = "/dev/urandom";
	str3 = "/dev/zero";
	if (ft_strcmp(map->argv, str1) == 0 || ft_strcmp(map->argv, str2) == 0
			|| ft_strcmp(map->argv, str3) == 0)
	{
		ft_putstr("NAZI ALERT!!!");
		exit(1);
	}
}

void		check_format_errors(t_info *info)
{
	if ((float)info->total / (float)info->height != (float)info->width)
	{
		ft_putstr("not correct format");
		info->error = 1;
		exit(1);
	}
}
