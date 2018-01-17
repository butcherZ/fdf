/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:52:33 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/12 02:53:39 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	cc;

	i = 0;
	ptr = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == cc)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
