/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:22:25 by sandre-a          #+#    #+#             */
/*   Updated: 2024/11/08 11:53:33 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_lstadd_front function adds a new node at the beginning of a list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->prev = NULL;
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		(*lst) = new;
	}
}
