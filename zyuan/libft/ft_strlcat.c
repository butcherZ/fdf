/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:11:12 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:25:03 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t i;
	size_t holder;

	i = 0;
	dst_len = ft_strlen(dst);
	holder = dst_len;
	src_len = ft_strlen(src);
	if (src == NULL || dst == NULL)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && dst_len < (size - 1))
		{
			dst[dst_len] = src[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = '\0';
	}
	if (size > dst_len)
		return (holder + src_len);
	else
		return (src_len + size);
}
