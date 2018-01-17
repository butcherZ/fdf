/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:36:05 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 12:00:35 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0)
		return (ft_isalpha(c));
	else if (ft_isdigit(c) != 0)
		return (ft_isdigit(c));
	else
		return (0);
}
