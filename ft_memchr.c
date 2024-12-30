/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:45:30 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:04 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_memchr function locates the first occurrence of a byte with the 
* given value c in the memory area starting at the location pointed to by s.
* The memory area is of length n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	character;

	p = (unsigned char *) s;
	character = (unsigned char ) c;
	while (n)
	{
		if (*p == character)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
