/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:54:23 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 16:14:14 by tcoze            ###   ########.fr       */
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
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, data->exit_path, \
			&data->width, &data->height);
	if (data->exit == NULL)
		return (exit_end_game(data));
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, \
			data->collectible_path, &data->width, &data->height);
	if (data->collectible == NULL)
		return (exit_end_game(data));
	data->fence1 = mlx_xpm_file_to_image(data->mlx_ptr, data->fence1_path, \
			&data->width, &data->height);
	if (data->fence1 == NULL)
		return (exit_end_game(data));
	data->fence2 = mlx_xpm_file_to_image(data->mlx_ptr, data->fence2_path, \
				&data->width, &data->height);
	if (data->fence2 == NULL)
		return (exit_end_game(data));
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, data->ground_path, \
				&data->width, &data->height);
	if (data->ground == NULL)
		return (exit_end_game(data));
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, data->player_path, \
				&data->width, &data->height);
	if (data->player == NULL)
		return (exit_end_game(data));
	return (0);
}

static void	fill_ind(t_ind *ind)
{
	ind->x = 0;
	ind->y = 0;
	ind->i = 0;
}

void	file_to_window(t_data *data)
{
	t_ind	ind;

	fill_ind(&ind);
	while (data->map[ind.i])
	{
		ind.n = 0;
		while (data->map[ind.i][ind.n] != '\n' \
			&& data->map[ind.i][ind.n] != '\0')
		{
			if (data->map[ind.i][ind.n] == '1')
				case_one(data, &ind);
			else if (data->map[ind.i][ind.n] == '0')
				case_o(data, &ind);
			else if (data->map[ind.i][ind.n] == 'C')
				case_c(data, &ind);
			else if (data->map[ind.i][ind.n] == 'E')
				case_e(data, &ind);
			else if (data->map[ind.i][ind.n] == 'P')
				case_p(data, &ind);
			ind.n++;
		}
		ind.i++;
		ind.x = ind.x + 126;
		ind.y = 0;
	}
}
