/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:41:27 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/12 21:37:32 by tcoze            ###   ########.fr       */
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
#include "../libft/libft.h"
#include "../libft/gnl/get_next_line.h"

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
	int		pos_x;
	int 	pos_y;
	int 	pos_player_pic_x;
	int		pos_player_pic_y;
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
}	t_data;

int 	on_destroy(t_data *data);
int 	on_keypress(int keysym, t_data *data);
int 	file_to_image(t_data *data);
void    store_textures(t_data *data);
int		file_to_window(t_data *data);
int 	player_moove(int key, t_data *data);
int		count_collec(t_data *data);

#endif
