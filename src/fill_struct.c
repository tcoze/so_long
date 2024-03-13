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

void	store_textures(t_data *data)
{
	data->collectible_path = "./textures/collectible.xpm";
	data->exit_path = "./textures/exit.xpm";
	data->fence2_path = "./textures/fence1.xpm";
	data->fence1_path = "./textures/fence2.xpm";
	data->ground_path = "./textures/herb.xpm";
	data->player_path = "./textures/player.xpm";
}

int	file_to_image(t_data *data)
{
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, data->exit_path, &data->width, &data->height);
	if (data->exit == NULL)
		return (-1);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, data->collectible_path, &data->width, &data->height);
	if (data->collectible == NULL)
		return (-1);
	data->fence1 = mlx_xpm_file_to_image(data->mlx_ptr, data->fence1_path, &data->width, &data->height);
	if (data->fence1 == NULL)
			return (-1);
	data->fence2 = mlx_xpm_file_to_image(data->mlx_ptr, data->fence2_path, \
				&data->width, &data->height);
	if (data->fence2 == NULL)
		return (-1);
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, data->ground_path, \
				&data->width, &data->height);
	if (data->ground == NULL)
		return (-1);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, data->player_path, \
				&data->width, &data->height);
	if (data->player == NULL)
		return (-1);
	return (0);
}

int	file_to_window(t_data *data)
{
	int i;
	int n;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (data->map[i])
	{
		n = 0;
		while(data->map[i][n] != '\n' && data->map[i][n] != '\0')
		{
			if (data->map[i][n] == '1')
			{
				if (n == 0 || data->map[i][n + 1] == '\n' || data->map[i][n + 1] == '\0')
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->fence1, y, x);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->fence2, y, x);
				y = y + 126;
			}
			else if (data->map[i][n] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, y, x);
				y = y + 126;
			}
			else if (data->map[i][n] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible, y, x);
				y = y + 126;
			}
			else if (data->map[i][n] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, y, x);
				y = y + 126;
			}
			else if (data->map[i][n] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, y, x);
				data->pos_x = x;
				data->pos_y = y;
				data->pos_player_pic_x = i;
				data->pos_player_pic_y = n;
				y = y + 126;
			}
			n++;
		}

		printf("\n");
		i++;
		x = x + 126;
		y = 0;
	}
	return (0);
}