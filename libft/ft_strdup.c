/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:56:40 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/14 03:57:55 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*dest;

	i = 0;
	len = ft_strlen(s);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
