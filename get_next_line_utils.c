/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:54:12 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 13:27:32 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	length_to_nl(t_gnl_list *lst)
{
	int	len;
	int	i;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			len++;
			if (lst->str[i++] == '\n')
				return (len);
		}
		lst = lst->next;
	}
	return (len);
}

bool	has_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i++] == '\n')
			return (true);
	}
	return (false);
}

char	*populate_string(t_gnl_list *lst, int len)
{
	char	*line;
	int		i;
	int		x;

	i = 0;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (lst)
	{
		x = 0;
		while (lst->str[x])
		{
			line[i++] = lst->str[x++];
			if (lst->str[x - 1] == '\n' || i == len)
				break ;
		}
		if (i == len)
			break ;
		lst = lst->next;
	}
	line[i] = '\0';
	return (line);
}

void	save_node(t_gnl_list **lst)
{
	char	*safe;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while ((*lst)->str[i] != '\n')
		i++;
	safe = malloc(BUFFER_SIZE + 1);
	if (safe)
	{
		while ((*lst)->str[++i])
			safe[x++] = (*lst)->str[i];
		safe[x] = '\0';
	}
	free((*lst)->str);
	(*lst)->str = safe;
}
