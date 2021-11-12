/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:06:24 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/12 14:26:32 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_malloc(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

void	ft_add_str(char *str, int index, long nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		ft_add_str(str, index - 1, nb / 10);
	str[index] = base[nb % 10];
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	nb;
	int		size;

	nb = (long)nbr;
	size = ft_size_malloc(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	ft_add_str(str, size, nb);
	str[size + 1] = '\0';
	return (str);
}

/*
** #include <stdio.h>
** #include <string.h>
** int	main(void)
** {
** 	char	*nb;
** 	nb = ft_itoa(-2147483648);
** 	printf("%s\n", nb);
** 	free(nb);
** 	nb = ft_itoa(2147483647);
** 	printf("%s\n", nb);
** 	free(nb);
** 	nb = ft_itoa(0);
** 	printf("%s\n", nb);
** 	free(nb);
** }
*/
