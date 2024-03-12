/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:27 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/14 03:48:44 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!((char *) dest) && !((char *) src))
		return (NULL);
	while (n != 0)
	{
		n--;
		((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
