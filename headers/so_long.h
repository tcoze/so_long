/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:41:27 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:11:16 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_SO_LONG_H
#define SO_LONG_SO_LONG_H

#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <fcntl.h>
#include "../libft/headers/libft.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_D 100
#define KEY_S 115
#define KEY_ESCAPE 65307

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**ctrl_map;
	int		pos_x;
	int 	pos_y;
	int 	pos_px;
	int		pos_py;
	int		height;
	int		width;
	char 	*player_path;
	void	*player;
	char 	*exit_path;
	void	*exit;
	char 	*fence1_path;
	void	*fence1;
	char 	*fence2_path;
	void	*fence2;
	char 	*collectible_path;
	void	*collectible;
	char 	*ground_path;
	void	*ground;
	int 	collectable;
	int 	collect;
	int 	y_max;
	int 	x_max;
	int		moove;
}	t_data;

int 	file_to_image(t_data *data);
void    store_textures(t_data *data);
int		file_to_window(t_data *data);
int 	player_moove(int key, t_data *data);
int		count_collec(t_data *data);
int		ft_check_argc(int argc, char **argv, t_data *data);
void	ft_freeall(char **out, int j);
int		ft_count_path(char **path);
int		control_map(t_data *data);
int		control_carac(t_data *data);
int		control_wall(t_data *data);
int		control_line(char **map);
int		control_pec(t_data *data);
int		control_ecp(t_data *data, char ecp);
int		flood_map(char **map, int x, int y);
void	ft_freedouble(char **map1, char **map2);
int		exit_end_game(t_data *data);

#endif
