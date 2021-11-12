/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:00:44 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/12 15:55:45 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

short	ft_is_charset(char c)
{
	if (c == '\0' || c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	ft_count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i]) && ft_is_charset(str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

void	ft_strcpy(char *tab, char *str)
{
	int	i;

	i = 0;
	while (!ft_is_charset(str[i]))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
}

void	ft_write(char **tab, char *str)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i]))
		{
			j = 0;
			while (!ft_is_charset(str[i + j]))
				j++;
			tab[index] = malloc(sizeof(char) * j + 1);
			ft_strcpy(tab[index], (str + i));
			index++;
			i += j;
		}
		else
			i++;
	}
	tab[index] = 0;
}

char	**ft_split(char *str)
{
	int		count;
	char	**tab;

	count = ft_count_word(str);
	tab = malloc(sizeof(char *) * count + 1);
	ft_write(tab, str);
	return (tab);
}


#include <stdio.h>

int	main(void)
{
	char **tab;

	printf("%d\n", ft_count_word("   /   \n   \t    ;   ceci \n  est umt test   ; \n"));
	tab = ft_split("   /   \n   \t    ;   ceci \n  est umt test   ; \n");
	for (int i = 0; tab[i]; i++)
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
	}
	free(tab);
}
