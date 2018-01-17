/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:31:53 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/10 21:33:11 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}