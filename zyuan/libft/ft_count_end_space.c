/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_end_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:46:00 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 12:02:50 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_end_space(char const *s)
{
	size_t	i;
	size_t	counter;
	size_t	len;

	len = ft_strlen(s);
	i = len - 1;
	if (len == 0)
		return (0);
	counter = 0;
	while (i > 0 && ft_isspace(s[i]) == 1)
	{
		counter++;
		i--;
	}
	return (counter);
}
