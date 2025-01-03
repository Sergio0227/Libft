/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:47:22 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:13 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
 * The ft_strcount function returns the number of occurrences of the specified
 * character in the given string.
 */
int	ft_strcount_charset(const char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	while (*str)
	{
		i = -1;
		while (charset[++i])
			if (*str == charset[i])
				count++;
		str++;
	}
	return (count);
}
