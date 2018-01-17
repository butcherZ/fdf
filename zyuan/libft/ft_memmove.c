/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:59:48 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 13:29:42 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	size_t			i;

	cdst = dst;
	i = 0;
	if ((unsigned char *)src <= cdst)
		while (len > 0)
		{
			len--;
			*(cdst + len) = *((unsigned char*)src + len);
		}
	else
		while (i < len)
		{
			*(cdst + i) = (*((unsigned char*)src + i));
			i++;
		}
	return (dst);
}
