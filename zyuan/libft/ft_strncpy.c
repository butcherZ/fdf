/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 05:40:47 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/15 02:37:49 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len && src[i])
		dst[i] = src[i];
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
