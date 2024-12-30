/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:01:33 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:16 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_strlen function calculates the length of the string pointed to by str.
*/
size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (*str++)
		x++;
	return (x);
}
