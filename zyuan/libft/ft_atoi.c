/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:18:46 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 14:59:57 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char		*check_space(const char *str)
{
	int index;

	index = 0;
	while ((str[index] == ' ') || (str[index] == '\t') || (str[index] == '\v')
			|| (str[index] == '\f') || (str[index] == '\r'
				|| str[index] == '\n'))
	{
		str++;
	}
	return (str);
}

static int		if_long(int counter, int sign, int result)
{
	if (counter > 18 && sign == 1)
		return (-1);
	if (counter > 18 && sign == -1)
		return (0);
	if (sign == 1 && counter <= 18)
		return (result);
	if (sign == -1 && counter <= 18)
		return (-result);
	return (0);
}

int				ft_atoi(const char *str)
{
	int result;
	int index;
	int sign;
	int counter;

	result = 0;
	sign = 1;
	index = 0;
	counter = 0;
	str = check_space(str);
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while ((str[index] <= '9') && (str[index] >= '0'))
	{
		result = result * 10 + (str[index] - '0');
		index++;
		counter++;
	}
	return (if_long(counter, sign, result));
}
