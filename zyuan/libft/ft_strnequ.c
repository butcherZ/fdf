/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:18:31 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 15:50:06 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	while (s1[j] != '\0' && s2[j] != '\0' && i < n)
	{
		if (s1[j] == s2[j] && i < n)
			j++;
		else
			return (0);
		i++;
	}
	return (1);
}
