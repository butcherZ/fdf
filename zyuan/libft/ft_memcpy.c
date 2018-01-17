/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:34:45 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/10 23:03:28 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	size_t	i;

	cdst = dst;
	i = 0;
	while (i < n)
	{
		*(cdst + i) = *((unsigned char*)src + i);
		i++;
	}
	dst = cdst;
	return (dst);
}
