/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_beginning_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:49:10 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 11:16:53 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_beginning_space(char const *s)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (ft_isspace(s[i]) == 1)
	{
		counter++;
		i++;
	}
	return (counter);
}
