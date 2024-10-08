/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:03:19 by sandre-a          #+#    #+#             */
/*   Updated: 2024/08/28 22:40:54 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	remaining_space;

	dst_len = 0;
	while (dst[dst_len] != 0 && dst_len < size)
		dst_len++;
	remaining_space = size - dst_len;
	if (remaining_space == 0 || size == 0)
		return (dst_len + ft_strlen(src));
	i = 0;
	while (src[i] != 0 && i < remaining_space - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + ft_strlen(src));
}
