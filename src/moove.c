/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:33:20 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/13 15:33:20 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

int	moove_s (t_data *data)
{
	if (data->map[data->pos_player_pic_x + 1][data->pos_player_pic_y] != '1')
	{
		if (data->map[data->pos_player_pic_x + 1][data->pos_player_pic_y] == 'C')
		{
			data->collect++;
			dprintf(2, "collectible collected : %d\n", data->collect);
			data->map[data->pos_player_pic_x + 1][data->pos_player_pic_y] = '0';
		}
		if (data->map[data->pos_player_pic_x + 1][data->pos_player_pic_y] == 'E')
		{
			if (data->collect == data->collectable)
				exit(0);
			else
				return(0);
		}
		data->pos_player_pic_x = data->pos_player_pic_x + 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->pos_x, data->pos_y);
		data->pos_y = data->pos_y + 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, data->pos_x, data->pos_y);
//		printf("position x : %d\n", data->pos_x);
//		printf("position y : %d\n", data->pos_y);
	}
	return (0);
}

int	moove_w (t_data *data)
{
	if (data->map[data->pos_player_pic_x - 1][data->pos_player_pic_y] != '1')
	{
		if (data->map[data->pos_player_pic_x - 1][data->pos_player_pic_y] == 'C')
		{
			data->collect++;
			dprintf(2, "collectible collectted : %d\n", data->collect);
			data->map[data->pos_player_pic_x - 1][data->pos_player_pic_y] = '0';
		}
		if (data->map[data->pos_player_pic_x - 1][data->pos_player_pic_y] == 'E')
		{
			if (data->collect == data->collectable)
				exit(0);
			else
				return(0);
		}
		data->pos_player_pic_x = data->pos_player_pic_x - 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->pos_x, data->pos_y);
		data->pos_y = data->pos_y - 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, data->pos_x, data->pos_y);
//		printf("position x : %d\n", data->pos_x);
//		printf("position y : %d\n", data->pos_y);
	}
	return (0);
}

int	moove_a (t_data *data)
{
	if (data->map[data->pos_player_pic_x][data->pos_player_pic_y - 1] != '1')
	{
		if (data->map[data->pos_player_pic_x][data->pos_player_pic_y - 1] == 'C')
		{
			data->collect++;
			dprintf(2, "collectible collected : %d\n", data->collect);
			data->map[data->pos_player_pic_x][data->pos_player_pic_y - 1] = '0';
		}
		if (data->map[data->pos_player_pic_x][data->pos_player_pic_y - 1] == 'E')
		{
			if (data->collect == data->collectable)
				exit(0);
			else
				return(0);
		}
		data->pos_player_pic_y = data->pos_player_pic_y - 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->pos_x, data->pos_y);
		data->pos_x = data->pos_x - 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, data->pos_x, data->pos_y);
//		printf("position x : %d\n", data->pos_x);
//		printf("position y : %d\n", data->pos_y);
	}
	return (0);
}

int	moove_d (t_data *data)
{
	if (data->map[data->pos_player_pic_x][data->pos_player_pic_y + 1] != '1')
	{
		if (data->map[data->pos_player_pic_x][data->pos_player_pic_y + 1] == 'C')
		{
			data->collect++;
			dprintf(2, "collectible collected : %d\n", data->collect);
			data->map[data->pos_player_pic_x][data->pos_player_pic_y + 1] = '0';
		}
		if (data->map[data->pos_player_pic_x][data->pos_player_pic_y + 1] == 'E')
		{
			if (data->collect == data->collectable)
				exit(0);
			else
				return(0);
		}
		data->pos_player_pic_y = data->pos_player_pic_y + 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, data->pos_x, data->pos_y);
		data->pos_x = data->pos_x + 126;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, data->pos_x, data->pos_y);
//		printf("position x : %d\n", data->pos_x);
//		printf("position y : %d\n", data->pos_y);
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
		exit(0);
	return (0);
}
