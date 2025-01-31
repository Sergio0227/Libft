/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:19:13 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:07 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_memset function fills the first n bytes of the memory area 
* pointed to by s with the specified byte c.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointer;

	pointer = (unsigned char *) s;
	while (n != 0)
	{
		*pointer = (unsigned char) c;
		pointer++;
		n--;
	}
	return (s);
}
