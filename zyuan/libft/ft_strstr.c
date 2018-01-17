/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 04:11:07 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 13:41:16 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = (char *)haystack;
	if (needle[0] == '\0')
		return (ptr);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				return (ptr + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
