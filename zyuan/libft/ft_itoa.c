/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:12:45 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 16:41:04 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*if_negative(int n, int len, int *i, int *j)
{
	char *str;

	*i = len;
	*j = len;
	if (n >= 0)
		str = (char*)malloc(sizeof(char) * (len + 1));
	else
		str = (char*)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	return (str);
}

static void	convert(long *nb, int *i, int *reminder, char *str)
{
	while (*nb >= 10 && *i > 0)
	{
		*reminder = *nb % 10;
		*nb = *nb / 10;
		str[*i - 1] = *reminder + 48;
		(*i)--;
	}
	str[0] = *nb + 48;
}

static void	convert_negative(long *nb, int *j, int *reminder, char *str)
{
	while (*nb <= -10 && *j > 0)
	{
		*reminder = (-(*nb)) % 10;
		*nb = *nb / 10;
		str[*j] = *reminder + 48;
		(*j)--;
	}
	str[0] = '-';
	str[1] = (-(*nb)) + 48;
}

static void	head_tail(long nb, int len, char *str)
{
	str[0] = nb + 48;
	str[len] = '\0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		reminder;
	long	nb;

	nb = n;
	if ((str = if_negative(n, ft_count_digits(n), &i, &j)) == NULL)
		return (NULL);
	if (nb > 10)
	{
		convert(&nb, &i, &reminder, str);
		str[ft_count_digits(n) + 1] = '\0';
	}
	if (nb < 0)
	{
		convert_negative(&nb, &j, &reminder, str);
		str[ft_count_digits(n) + 1] = '\0';
	}
	else if (nb < 10)
		head_tail(nb, ft_count_digits(n), str);
	return (str);
}
