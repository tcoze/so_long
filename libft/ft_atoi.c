/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:34:32 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 21:25:43 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_checksign(char c);

static int	ft_checksign(char c)
{
	int	i;

	i = 1;
	if (c == '-')
		i = -1;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long int	nb;
	int			signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((nptr[i] <= '\r' && nptr[i] >= '\t') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		signe = ft_checksign(nptr[i++]);
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + (nptr[i] - '0');
		if (nb < 0)
		{
			if (nptr[0] == '-')
				return (0);
			return (-1);
		}
		i++;
	}
	return (signe * nb);
}
