/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:04:04 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:29:25 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(fresh = malloc(sizeof(char) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		fresh[i] = s2[j];
		j++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
