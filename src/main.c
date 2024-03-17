/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:41:42 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:14:34 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_initiate(t_data *data)
{
	data->map = NULL;
	data->ctrl_map = NULL;
	data->moove = 0;
	data->pos_px = 0;
	data->pos_py = 0;
	data->collect = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_initiate(&data);
	if (ft_check_argc(argc, argv, &data) == -1)
		return (-1);
	if (control_map(&data) == -1)
		return (-1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.y_max + 1) \
		* 126, (data.x_max + 1) * 126, "Walk with ego");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), ft_freedouble(data.map, data.ctrl_map), 1);
	store_textures(&data);
	file_to_image(&data);
	count_collec(&data);
	file_to_window(&data);
	mlx_key_hook(data.win_ptr, player_moove, &data);
	mlx_hook (data.win_ptr, 17, 1L << 0, exit_end_game, &data);
	mlx_loop (data.mlx_ptr);
	return (0);
}
