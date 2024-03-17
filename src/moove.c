/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:33:20 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:03:23 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	moove_s(t_data *data)
{
	if (data->map[data->pos_py + 1][data->pos_px] != '1')
	{
		if (data->map[data->pos_py + 1][data->pos_px] == 'C')
		{
			data->collect++;
			data->map[data->pos_py + 1][data->pos_px] = '0';
		}
		if (data->map[data->pos_py + 1][data->pos_px] == 'E')
		{
			if (data->collect == data->collectable)
				exit_end_game(data);
			else
				return (0);
		}
		data->pos_py = data->pos_py + 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, \
			data->pos_y, data->pos_x);
		data->pos_x = data->pos_x + 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, \
			data->pos_y, data->pos_x);
		data->moove++;
		ft_printf(1, "Number of steps : %d\n", data->moove);
	}
	return (0);
}

int	moove_w(t_data *data)
{
	if (data->map[data->pos_py - 1][data->pos_px] != '1')
	{
		if (data->map[data->pos_py - 1][data->pos_px] == 'C')
		{
			data->collect++;
			data->map[data->pos_py - 1][data->pos_px] = '0';
		}
		if (data->map[data->pos_py - 1][data->pos_px] == 'E')
		{
			if (data->collect == data->collectable)
				exit_end_game(data);
			else
				return (0);
		}
		data->pos_py = data->pos_py - 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, \
			data->pos_y, data->pos_x);
		data->pos_x = data->pos_x - 126;
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player, \
			data->pos_y, data->pos_x);
		data->moove++;
		ft_printf(1, "Number of steps : %d\n", data->moove);
	}
	return (0);
}

int	moove_a(t_data *data)
{
	if (data->map[data->pos_py][data->pos_px - 1] != '1')
	{
		if (data->map[data->pos_py][data->pos_px - 1] == 'C')
		{
			data->collect++;
			data->map[data->pos_py][data->pos_px - 1] = '0';
		}
		if (data->map[data->pos_py][data->pos_px - 1] == 'E')
		{
			if (data->collect == data->collectable)
				exit_end_game(data);
			else
				return (0);
		}
		data->pos_px = data->pos_px - 1;
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->ground, \
			data->pos_y, data->pos_x);
		data->pos_y = data->pos_y - 126;
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player, \
			data->pos_y, data->pos_x);
		data->moove++;
		ft_printf(1, "Number of steps : %d\n", data->moove);
	}
	return (0);
}

int	moove_d(t_data *data)
{
	if (data->map[data->pos_py][data->pos_px + 1] != '1')
	{
		if (data->map[data->pos_py][data->pos_px + 1] == 'C')
		{
			data->collect++;
			data->map[data->pos_py][data->pos_px + 1] = '0';
		}
		if (data->map[data->pos_py][data->pos_px + 1] == 'E')
		{
			if (data->collect == data->collectable)
				exit_end_game(data);
			else
				return (0);
		}
		data->pos_px = data->pos_px + 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, \
			data->pos_y, data->pos_x);
		data->pos_y = data->pos_y + 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, \
			data->pos_y, data->pos_x);
		data->moove++;
		ft_printf(1, "Number of steps : %d\n", data->moove);
	}
	return (0);
}

int	player_moove(int key, t_data *data)
{
	if (key == KEY_A)
		moove_a(data);
	if (key == KEY_W)
		moove_w(data);
	if (key == KEY_S)
		moove_s(data);
	if (key == KEY_D)
		moove_d(data);
	if (key == KEY_ESCAPE)
		exit_end_game(data);
	return (0);
}
