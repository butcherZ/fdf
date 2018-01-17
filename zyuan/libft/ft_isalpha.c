/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:17:14 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/22 12:07:22 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (ft_isupper(c) != 0)
		return (ft_isupper(c));
	else if (ft_islower(c) != 0)
		return (ft_islower(c));
	else
		return (0);
}
