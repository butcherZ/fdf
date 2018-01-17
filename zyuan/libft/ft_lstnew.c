/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:18:53 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 17:26:27 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh;

	fresh = (t_list*)malloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	fresh->content = malloc(sizeof(char) * (content_size + 1));
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
