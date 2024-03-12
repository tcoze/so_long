/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:08:02 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:27:23 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	strlen;

	i = 0;
	strlen = ft_strlen(s);
	str = ft_calloc(strlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < strlen)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
