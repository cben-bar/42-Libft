/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:10:10 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/16 22:54:09 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *src, size_t n)
{
	char	*dest;
	size_t	i;

	dest = malloc(n + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	i_beg;
	size_t	i_end;

	i_beg = 0;
	i_end = 0;
	i = 0;
	while (s[i_end])
	{
		if (s[i_end] == c)
		{
			if (i_end > i_beg)
				i++;
			i_beg = i_end + 1;
		}
		i_end++;
	}
	if (i_end > i_beg)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**string;
	size_t		i_beg;
	size_t		i_end;
	size_t		i;

	string = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!string)
		return (NULL);
	i_beg = 0;
	i_end = 0;
	i = 0;
	while (s[i_end])
	{
		if (s[i_end] == c)
		{
			if (i_end > i_beg)
				string[i++] = ft_strndup (s + i_beg, i_end - i_beg);
			i_beg = i_end + 1;
		}
		i_end++;
	}
	if (i_end > i_beg)
		string[i++] = ft_strndup (s + i_beg, i_end - i_beg);
	string[i] = NULL;
	return (string);
}
