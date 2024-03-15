/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:44:42 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/15 16:44:42 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	afficher_map(char **map)
{
	int z;
	int y;

	z = 0;
	while (map[z])
	{
		y = 0;
		while (map[z][y] != '\n' && map[z][y] != '\0')
		{
			dprintf(2, "%c", map[z][y]);
			y++;
		}
		z++;
		printf("\n");
	}
}

static int control_carac(t_data *data)
{
	int i;
	int j;

	i = 0;;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] != 'E' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'P' && data->map[i][j] != '0'
				&& data->map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	control_wall(t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	data->y_max = ft_strlen(data->map[x]) - 2;
	while (y <= data->y_max && data->map[x])
	{
		dprintf(2, "%c", data->map[x][y]);
		if (data->map[x][y] != '1')
			return (-1);
		y++;
	}
	dprintf(2, "\n\n");
	dprintf(2, "xmax = %d\n", data->x_max);
	dprintf(2, "ymax = %d\n", data->y_max);
	while (x <= data->x_max && data->map[x])
	{
		dprintf(2, "x = %d\n", x);
		dprintf(2, "%c\n", data->map[x][0]);
		dprintf(2, "%c\n", data->map[x][data->y_max]);
		if (data->map[x][0] != '1' || data->map[x][data->y_max] != '1')
			return (-1);
		x++;
	}
	y = 0;
	x = x - 1;
	dprintf(2, "x = %d\n", x);
	while (y <= data->y_max && data->map[x])
	{
		if (data->map[x][y] != '1')
			return (-1);
		y++;
	}
	return (0);
}

static int control_line(char **map)
{
	int i;
	int j;

	size_t len;
	size_t temp;
	i = 0;
	len = ft_strlen(map[0]);
	if (len < 3)
		return (-1);
	while (map[i])
		i++;
	if (i < 2)
		return (-1);
	j = 0;
	while (j < i - 1)
	{
		temp = ft_strlen(map[j]);
		if (len != temp)
			return (-1);
		j++;
	}
	if (ft_strlen(map[j]) != len - 1)
		return (-1);
	return (0);
}

static int control_pec(t_data *data)
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (data->ctrl_map[i])
	{
		j = 0;
		while (data->ctrl_map[i][j] != '\n' && data->ctrl_map[i][j] != '\0')
		{
			if (data->ctrl_map[i][j] == 'E' || data->ctrl_map[i][j] == 'C'
			|| data->ctrl_map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 0)
		return (-1);
	return (0);
}

static int control_ecp(t_data *data, char ecp)
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == ecp)
			{
				if (ecp == 'P')
				{
					data->pos_player_pic_x = i;
					data->pos_player_pic_y = j;
				}
				count++;
			}j++;
		}
		i++;
	}
	if (ecp == 'E' || ecp == 'P')
		if (count != 1)
			return (-1);
	if (ecp == 'C')
		if (count < 1)
			return (-1);
	return (0);
}

static int flood_map(char **map, int x, int y)
{
	if (map[x][y] == 'X' || map[x][y] == '1' )//|| map[x][y] == 'E')
		return (0);
	map[x][y] = 'X';
	flood_map(map, x + 1, y);
	flood_map(map, x - 1, y);
	flood_map(map, x, y + 1);
	flood_map(map, x, y - 1);
	return (0);
}

int	control_map(t_data *data)
{
	dprintf(2, "MAP PRE CONTROL\n");
	afficher_map (data->map);
	if (control_ecp(data, 'E') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_ecp(data, 'C') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_ecp(data, 'P') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	dprintf(2, "TEST ECP OK\n");
	if (control_line(data->map) == -1)
		return (-1);
	dprintf(2, "TEST LEN OK\n");
	if (control_wall(data) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	dprintf(2, "TEST WALL OK\n");
	if (control_carac(data) == -1)
		return (-1);
	dprintf(2, "TEST CARAC OK\n");
	flood_map(data->ctrl_map, data->pos_player_pic_x, data->pos_player_pic_y);
	if (control_pec(data) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	dprintf(2, "TEST FLOOD OK\n");
	return (0);
}