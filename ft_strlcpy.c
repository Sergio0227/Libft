/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:46 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:16 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_strlcpy function copies up to size - 1 characters from the string
*  src to the string dst, and always null-terminates dst.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		length;

	i = 0;
	length = ft_strlen(src);
	if (!size)
		return (length);
	while (src[i] != 0 && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (length);
}
