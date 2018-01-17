/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:58:51 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:32:15 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*fresh;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (fresh == 0)
		return (0);
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
