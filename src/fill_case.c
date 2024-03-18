/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:09:46 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 16:12:58 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	case_c(t_data *data, t_ind *ind)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->collectible, ind->y, ind->x);
	ind->y = ind->y + 126;
}

void	case_o(t_data *data, t_ind *ind)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->ground, ind->y, ind->x);
	ind->y = ind->y + 126;
}

void	case_p(t_data *data, t_ind *ind)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->player, ind->y, ind->x);
	data->pos_x = ind->x;
	data->pos_y = ind->y;
	data->pos_px = ind->n;
	data->pos_py = ind->i;
	ind->y = ind->y + 126;
}

void	case_one(t_data *data, t_ind *ind)
{
	if (ind->n == 0 || data->map[ind->i][ind->n + 1] == '\n' ||
			data->map[ind->i][ind->n + 1] == '\0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->fence1, ind->y, ind->x);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->fence2, ind->y, ind->x);
	ind->y = ind->y + 126;
}

void	case_e(t_data *data, t_ind *ind)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->exit, ind->y, ind->x);
	ind->y = ind->y + 126;
}
