/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:39:39 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 13:39:49 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	cc;
	int		i;

	i = 0;
	cc = c;
	ptr = (char *)s;
	if (!*ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			return (ptr + i);
		}
		i++;
	}
	if (cc == '\0')
		return (ptr + i);
	return (NULL);
}
