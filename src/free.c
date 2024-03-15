/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:34:49 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/15 16:34:49 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_freedouble(char **map1, char **map2)
{
	ft_freeall(map1, ft_count_path(map1));
	ft_freeall(map2, ft_count_path(map2));
}

void	ft_freeall(char **out, int j)
{
	if (out != NULL)
	{
		while (j > -1)
		{
			if (out[j])
				free (out[j]);
			j--;
		}
		if (out)
			free (out);
	}
}

int	ft_count_path(char **path)
{
	int	i;

	i = 0;
	if (path == NULL)
		return (-1);
	while (path[i] && path[i + 1])
		i++;
	return (i);
}