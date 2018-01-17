/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:33:27 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 16:46:33 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = ft_strnew(len);
	if (fresh == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
