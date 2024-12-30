/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:59:28 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 13:27:33 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst = NULL;
	char				*line;
	int					len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &lst);
	len = length_to_nl(lst);
	if (!lst || !len)
		return (NULL);
	line = populate_string(lst, len);
	clean_memory(&lst);
	if (lst)
		save_node(&lst);
	return (line);
}

void	read_line(int fd, t_gnl_list **lst)
{
	int		chars_read;
	char	*buffer;

	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[chars_read] = '\0';
		stash_into_list(lst, buffer);
		if (has_new_line(buffer))
			break ;
	}
}

void	stash_into_list(t_gnl_list **lst, char *buffer)
{
	t_gnl_list	*new_node;
	t_gnl_list	*temp;

	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
	{
		free(buffer);
		return ;
	}
	new_node->str = buffer;
	new_node->next = NULL;
	if (!*lst)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	clean_memory(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	while (*lst && !has_new_line((*lst)->str))
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->str);
		free(temp);
	}
}
