/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:29:07 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/15 20:33:46 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	p;
	char	*out;

	if (!*set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	p = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[p]))
		p--;
	out = ft_calloc(p + 2, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s1, p + 1);
	return (out);
}
