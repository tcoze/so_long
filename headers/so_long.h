/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:41:27 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/12 19:29:04 by tcoze            ###   ########.fr       */
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

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
//	t_map		*map;
}	t_data;

typedef struct	s_picture
{
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
}	t_picture;

int 	on_destroy(t_data *data);
int 	on_keypress(int keysym, t_data *data);
int 	file_to_image(t_picture *pics, t_data *data);
void    store_textures(t_picture *pics);
int		file_to_window(t_picture *pics, t_data *data);

#endif
