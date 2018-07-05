/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 03:20:21 by zyuan             #+#    #+#             */
/*   Updated: 2018/07/05 03:20:35 by zyuan            ###   ########.fr       */
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

void		check_format_and_free(char **line, char **tab, t_info *info)
{
	check_format_errors(info);
	free_everything(line, tab, info);
}
