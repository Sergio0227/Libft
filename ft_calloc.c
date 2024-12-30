/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:53:43 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:42:43 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_calloc function allocates memory for a specified number of elements, 
* each of a specified size, and initializes the allocated memory to zero. 
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (nmemb && size && nmemb > (4294967295 / size))
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nmemb * size);
	return (pointer);
}
