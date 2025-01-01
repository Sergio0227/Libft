/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:54:12 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/01 18:17:31 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

t_list	*get_last_node(t_list *stash)
{
	if (!stash)
		return (NULL);
	while (stash->next)
	{
		stash = stash->next;
	}
	return (stash);
}

int	len_to_nl(t_list *stash)
{
	int	i;
	int	length;

	length = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				length++;
				return (length);
			}
			length++;
			i++;
		}
		stash = stash->next;
	}
	return (length);
}

void	copy_str(t_list *stash, char *str)
{
	int	i;
	int	x;

	if (!stash)
		return ;
	i = 0;
	while (stash)
	{
		x = 0;
		while (stash->content[x])
		{
			if (stash->content[x] == '\n')
			{
				str[i++] = '\n';
				str[i] = 0;
				return ;
			}
			str[i++] = stash->content[x++];
		}
		stash = stash->next;
	}
	str[i] = 0;
}

void	clean(t_list **stash)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean = malloc(sizeof(t_list));
	if (!buffer || !clean)
		return ;
	last = get_last_node(*stash);
	i = 0;
	k = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	while (last->content[i] && last->content[++i])
		buffer[k++] = last->content[i];
	buffer[k] = 0;
	clean->content = buffer;
	clean->next = NULL;
	dealloc(stash, clean, buffer);
}

void	dealloc(t_list **stash, t_list *clean_node, char *buffer)
{
	t_list	*temp;

	if (!stash)
		return ;
	while (*stash)
	{
		temp = (*stash)->next;
		free((*stash)->content);
		free(*stash);
		*stash = temp;
	}
	*stash = NULL;
	if (clean_node->content[0])
		*stash = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}
