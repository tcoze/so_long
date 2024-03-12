/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:45:28 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:35:22 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*out;
	size_t		slen;
	size_t		sslen;

	i = 0;
	slen = ft_strlen(s) - start;
	sslen = ft_strlen(s);
	if (slen > len)
		slen = len;
	if (start > sslen)
		slen = 0;
	out = ft_calloc(slen + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (start < sslen && len > 0)
	{
		out[i] = s[start];
		start++;
		i++;
		len--;
	}
	return (out);
}
