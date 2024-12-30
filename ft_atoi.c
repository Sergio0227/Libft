/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:17:11 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:42:39 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_atoi function converts a string to an integer, 
* handling optional signs and leading whitespace.
*/
int	ft_atoi(const char *nptr)
{
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	result *= sign;
	return ((int) result);
}
