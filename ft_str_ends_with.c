/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 02:18:06 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:10 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
 * Determines whether the given string ends with a specified substring.
 */

int	ft_str_ends_with(const char *str, const char *end)
{
	int	size;

	if (ft_strlen(str) < ft_strlen(end) || !str || !end)
		return (0);
	size = ft_strlen(end);
	str += ft_strlen(str) - 1;
	end += size - 1;
	while (size - 1)
	{
		if (*str != *end)
			return (0);
		str--;
		end--;
		size--;
	}
	return (1);
}
