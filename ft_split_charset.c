/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:29:40 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/02 22:46:48 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
 * The ft_split function splits a string into words,
 * using a charset and returns an array of strings.
 */

static int	count_words(const char *str, char *sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_strchr(sep, *str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_strchr(sep, *str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*get_next_word(const char **str, char *sep)
{
	const char	*start;
	size_t		len;

	while (**str && ft_strchr(sep, **str))
		(*str)++;
	start = *str;
	while (**str && !ft_strchr(sep, **str))
		(*str)++;
	len = *str - start;
	return (ft_substr(start, 0, len));
}

char	**ft_split_charset(char const *str, char *sep)
{
	char	**strings;
	int		word_count;
	int		i;

	if (!str)
		return (NULL);
	word_count = count_words(str, sep);
	strings = malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		strings[i] = get_next_word(&str, sep);
		if (!strings[i])
		{
			while (i > 0)
				free(strings[--i]);
			free(strings);
			return (NULL);
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
