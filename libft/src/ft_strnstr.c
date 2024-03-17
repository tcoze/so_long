/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:53:15 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/17 23:48:21 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	p;

	i = 0;
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if (!little[0])
		return ((char *)big);
	while (big[i])
	{
		p = 0;
		while (big[p + i] == little[p] && i + p < len)
		{
			p++;
			if (little[p] == 0)
				return (((char *)big) + i);
		}
		i++;
	}
	return (NULL);
}
