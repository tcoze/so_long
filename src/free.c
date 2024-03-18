/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:34:49 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 15:41:35 by tcoze            ###   ########.fr       */
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

static void	destroy_img(t_data *data)
{
	if (data->collectible != NULL)
		mlx_destroy_image(data->mlx_ptr, data->collectible);
	if (data->fence1 != NULL)
		mlx_destroy_image(data->mlx_ptr, data->fence1);
	if (data->fence2 != NULL)
		mlx_destroy_image(data->mlx_ptr, data->fence2);
	if (data->ground != NULL)
		mlx_destroy_image(data->mlx_ptr, data->ground);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->exit != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit);
}

int	exit_end_game(t_data *data)
{
	ft_freeall(data->map, ft_count_path(data->map));
	destroy_img(data);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
