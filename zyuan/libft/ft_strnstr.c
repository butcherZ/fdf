/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 04:11:07 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 14:12:30 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	ptr = (char *)haystack;
	if (needle[0] == '\0')
		return (ptr);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' &&
				haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0' && i + j < len)
				return (ptr + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
