/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:39:39 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 14:24:46 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*ptr;
	char		cc;
	size_t		len;

	cc = c;
	len = ft_strlen(s);
	ptr = (char *)s;
	if (!*ptr)
		return (NULL);
	while (len + 1 > 0)
	{
		if (s[len] == cc)
		{
			return (ptr + len);
		}
		len--;
	}
	if (cc == '\0')
		return (ptr + len);
	return (NULL);
}
