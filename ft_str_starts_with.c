/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 02:06:46 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:12 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* Determines whether the given string starts with a specified substring. 
*/

int	ft_str_starts_with(const char *str, const char *start)
{
	if (ft_strlen(str) < ft_strlen(start))
		return (0);
	while (*start)
	{
		if (*str != *start)
			return (0);
		start++;
		str++;
	}
	return (1);
}
