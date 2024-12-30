/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:12:30 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:14 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_strdup function allocates sufficient memory for a copy of the 
* string s1, and returns a pointer to the allocated memory.
*/
char	*ft_strdup(const char *s)
{
	int		length;
	char	*t_s;
	char	*new_str;
	char	*start;

	t_s = (char *) s;
	length = ft_strlen(t_s);
	new_str = malloc((length + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	start = new_str;
	while (*t_s)
	{
		*new_str = *t_s;
		new_str++;
		t_s++;
	}
	*new_str = 0;
	return (start);
}
