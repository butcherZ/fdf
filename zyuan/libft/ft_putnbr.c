/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:09:22 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 13:34:48 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	long	nb_reminder;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		nb_reminder = nb % 10;
		nb = nb / 10;
		ft_putnbr(nb);
		ft_putchar(nb_reminder + 48);
	}
	else if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
}
