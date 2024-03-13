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

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data data;
	int	fd;
	char *line;
	int	i;
	int	y;

	i = 0;
	y = 0;
	data.map = NULL;
	if (argc != 2)
		return (-1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 756, 756, "Walk with ego");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	store_textures(&data);
	file_to_image(&data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	data.map = malloc(sizeof(char *) * (1 + i));
	data.map[i] = NULL;
	while (y < i)
	{
		data.map[y] = get_next_line(fd);
		y++;
	}
	data.collec = 0;
	count_collec(&data);
	file_to_window (&data);
	mlx_key_hook(data.win_ptr, player_moove, &data);

	// Register destroy hook
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
