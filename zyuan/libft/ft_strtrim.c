/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 04:42:37 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:41:34 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char	*new;
	size_t	beginning;
	size_t	i;
	size_t	end;
	size_t	len;

	if (s == NULL)
		return (NULL);
	beginning = ft_count_beginning_space(s);
	end = ft_count_end_space(s);
	len = ft_strlen(s);
	if (len - beginning <= 0)
		return (ft_strdup(""));
	i = 0;
	new = ft_strnew(len - beginning - end);
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0' && beginning < len - end)
	{
		new[i] = s[beginning];
		i++;
		beginning++;
	}
	return (new);
}
