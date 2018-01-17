/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:32:32 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:33:19 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*fresh;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (fresh == 0)
		return (0);
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
