/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:33:42 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/12 23:51:13 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimmer(char c, char const *set)
{
	size_t	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

static size_t	ft_trimmer2(char c, char const *set)
{
	size_t	y;

	y = 0;
	while (set[y] != '\0')
	{
		if (set[y] ==c)
			return (1);
		y++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*s_trim;

	i = 0;
	j = ft_strlen(s1);
	l = 0;
	if (!set || !s1)
		return 	(ft_calloc(1, 1));
	while (i < j && s1[i] != '\0')
	{
		if (ft_trimmer(s1[i], set))
			i++;
		else
			break;
	}
	while ((j)  > i)
	{
		if (ft_trimmer2(s1[j], set))
			j--;
		else
			break;
	}
	k = j - i;
	s_trim = malloc(sizeof(char) * (k + 1));
		if(! s_trim)
			return (0);
	while (i < j)
	{
		s_trim[l] = s1[i];
		i++;
		l++;
	}
	s_trim[l] = '\0';
	return (s_trim);
}
