/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:51:34 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 11:25:38 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	nb_reminder;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		nb_reminder = nb % 10;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		ft_putchar_fd(nb_reminder + 48, fd);
	}
	else if (nb < 10)
	{
		ft_putchar_fd(nb + 48, fd);
	}
}
