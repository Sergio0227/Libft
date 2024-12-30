/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:06:47 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:20 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_strrchr function locates the last occurrence of the 
* character c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*p;

	p = (char *)s;
	size = ft_strlen(p);
	while (*p)
		p++;
	while (size >= 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		p--;
		size--;
	}
	return (NULL);
}
