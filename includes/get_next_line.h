/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:36:42 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 13:27:41 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_gnl_list
{
	char				*str;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						length_to_nl(t_gnl_list *lst);

char					*populate_string(t_gnl_list *lst, int len);

void					clean_memory(t_gnl_list **lst);

char					*get_next_line(int fd);

void					read_line(int fd, t_gnl_list **lst);

bool					has_new_line(char *buffer);

void					stash_into_list(t_gnl_list **lst, char *buffer);

void					save_node(t_gnl_list **lst);

#endif
