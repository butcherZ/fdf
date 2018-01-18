/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:57:29 by zyuan             #+#    #+#             */
/*   Updated: 2018/01/18 16:11:39 by zyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE 42

char	*realloc_and_append(char *str, char buffer[BUFF_SIZE + 1]);
t_list	*get_fd(int fd, t_list **list);
int		no_new_line(t_list *current, char **line);
int		split_line(t_list *current, char **line);
int		get_next_line(int fd, char **line);

#endif
