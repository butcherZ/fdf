/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:59:00 by zyuan             #+#    #+#             */
/*   Updated: 2018/01/18 16:09:38 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*realloc_and_append(char *content, char buffer[BUFF_SIZE + 1])
{
	char	*new;

	if (!content)
	{
		if ((content = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
			return (NULL);
		content = ft_strcpy(content, buffer);
		return (content);
	}
	if ((new = (char*)malloc(sizeof(char) *
					(ft_strlen(content) + BUFF_SIZE + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, content);
	new = ft_strcat(new, buffer);
	free(content);
	content = NULL;
	return (new);
}

t_list		*get_fd(int fd, t_list **fd_list)
{
	t_list	*current;

	current = *fd_list;
	while (current)
	{
		if (current->content_size == (size_t)(fd))
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(fd_list, current);
	return (current);
}

int			no_new_line(t_list *current, char **line)
{
	if (ft_strlen(current->content) == 0)
	{
		free(current->content);
		current->content = NULL;
		return (0);
	}
	*line = ft_strdup(current->content);
	free(current->content);
	current->content = NULL;
	return (1);
}

int			split_line(t_list *current, char **line)
{
	char	*n;
	char	*tmp;

	if (ft_strchr(current->content, '\n') != NULL)
	{
		*line = NULL;
		if ((n = ft_strstr(current->content, "\n")) == NULL)
			return (-1);
		if ((*line = malloc(sizeof(char) *
						((n - (char *)current->content + 1)))) == NULL)
			return (-1);
		ft_bzero(*line, n - (char *)current->content + 1);
		ft_memmove(*line, current->content, n - (char *)current->content);
		tmp = ft_strdup(n + 1);
		free(current->content);
		current->content = NULL;
		current->content = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	else
		return (no_new_line(current, line));
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*fd_list;
	t_list			*current;
	int				ret;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	current = get_fd(fd, &fd_list);
	ret = 1;
	while (((current->content == NULL) ||
				(ft_strchr(current->content, '\n') == NULL)) && (ret != 0))
	{
		ft_bzero(buffer, BUFF_SIZE + 1);
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1 || (ret == 0 && current->content == NULL))
		{
			free(current->content);
			current->content = NULL;
			return (ret);
		}
		current->content = realloc_and_append(current->content, buffer);
	}
	return (split_line(current, line));
}
