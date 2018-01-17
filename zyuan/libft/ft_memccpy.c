/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:31:22 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/13 18:08:16 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cdst;
	size_t	i;

	cdst = dst;
	i = 0;
	while (i < n)
	{
		*(cdst + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
