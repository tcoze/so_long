/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:44:35 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/14 03:50:39 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	while (src[i] && dest_len + i + 1 < size)
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	if (dest_len < size)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
