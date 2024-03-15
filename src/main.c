/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:41:42 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/12 21:36:49 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int main(int argc, char *argv[])
{
	t_data data;

	data.map = NULL;
	data.ctrl_map = NULL;
	if (ft_check_argc(argc, argv, &data) == -1)
		return (-1);
	if (control_map(&data) == -1)
		return (-1);
	data.pos_player_pic_x = 0;
	data.pos_player_pic_y = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.y_max + 1) * 1260, (data.x_max + 1) * 1260, "Walk with ego");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	store_textures(&data);
	file_to_image(&data);
	data.collect = 0;
	count_collec(&data);
	file_to_window (&data);
	mlx_key_hook(data.win_ptr, player_moove, &data);

	// Register destroy hook
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
