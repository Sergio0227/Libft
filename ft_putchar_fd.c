/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:55:23 by sandre-a          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:07 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
* The ft_putchar_fd function writes the character c to the file descriptor fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
