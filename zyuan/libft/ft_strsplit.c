/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:01:01 by zyuan             #+#    #+#             */
/*   Updated: 2018/02/02 15:38:53 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		num_words;

	i = 0;
	num_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			num_words++;
		}
		else
			i++;
	}
	return (num_words);
}

static void	ft_get_word(const char *s, char c, int *start, int *end)
{
	int		i;
	int		num_words;

	i = *end;
	num_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			*start = i;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			num_words++;
			*end = i;
			return ;
		}
		else
			i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*word;
	int		i;
	int		start;
	int		end;

	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!str || !s)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		ft_get_word(s, c, &start, &end);
		if (!(word = ft_strsub(s, start, end - start)))
			return (NULL);
		word[end - start] = '\0';
		str[i] = word;
		i++;
	}
	str[i] = (NULL);
	return (str);
}
