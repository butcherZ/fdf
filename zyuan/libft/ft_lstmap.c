/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:16:01 by zyuan             #+#    #+#             */
/*   Updated: 2017/11/23 18:22:51 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;
	t_list *tmp;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL || lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	head = new;
	while (lst->next != NULL)
	{
		tmp = f(lst->next);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
