/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:56:56 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:12:08 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checksign(long int nb);
static size_t	ft_nbr(long int nb);
static char		*ft_fill(char *number, long int nb1, int sign);

static int	checksign(long int nb)
{
	if (nb >= 0)
		return (0);
	return (1);
}

static size_t	ft_nbr(long int nb)
{
	size_t	i;

	i = 0;
	while (nb > 9 || nb < -9)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

static char	*ft_fill(char *number, long int nb1, int sign)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_nbr(nb1) - 1;
	number[j + 1] = '\0';
	if (sign)
	{
		number[0] = '-';
		nb1 = -nb1;
		i = 1;
	}
	if (nb1 == 0)
		number[0] = '0';
	while (nb1 != 0)
	{
		number[j + i] = nb1 % 10 + '0';
		nb1 = nb1 / 10;
		j--;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	long int	nb1;
	char		*number;

	nb1 = n;
	number = ft_calloc(sizeof(char), ft_nbr(nb1) + checksign(nb1) + 1);
	if (!number)
		return (NULL);
	number = ft_fill(number, nb1, checksign(nb1));
	return (number);
}
