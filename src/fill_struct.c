/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:54:23 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/11 16:54:23 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	store_textures(t_picture *pics)
{
	pics->collectible_path = "./textures/collectible.xpm";
	pics->exit_path = "./textures/exit.xpm";
	pics->fence2_path = "./textures/fence1.xpm";
	pics->fence1_path = "./textures/fence2.xpm";
	pics->ground_path = "./textures/herb.xpm";
	pics->player_path = "./textures/player.xpm";
}

int	file_to_image(t_picture *pics, t_data *data)
{
	pics->exit = mlx_xpm_file_to_image(data->mlx_ptr, pics->exit_path, &pics->width, &pics->height);
	if (pics->exit == NULL)
		return (-1);
	pics->collectible = mlx_xpm_file_to_image(data->mlx_ptr, pics->collectible_path, &pics->width, &pics->height);
	if (pics->collectible == NULL)
		return (-1);
	pics->fence1 = mlx_xpm_file_to_image(data->mlx_ptr, pics->fence1_path, &pics->width, &pics->height);
	if (pics->fence1 == NULL)
			return (-1);
	pics->fence2 = mlx_xpm_file_to_image(data->mlx_ptr, pics->fence2_path, \
				&pics->width, &pics->height);
	if (pics->fence2 == NULL)
		return (-1);
	pics->ground = mlx_xpm_file_to_image(data->mlx_ptr, pics->ground_path, \
				&pics->width, &pics->height);
	if (pics->ground == NULL)
		return (-1);
	pics->player = mlx_xpm_file_to_image(data->mlx_ptr, pics->player_path, \
				&pics->width, &pics->height);
	if (pics->player == NULL)
		return (-1);
}

int	file_to_window(t_picture *pics, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->exit, 500, 500);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->collectible, 1000, 500);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->fence1, 1500, 300);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->ground, 300, 300);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->player, 100, 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pics->fence2, 750, 750);
}