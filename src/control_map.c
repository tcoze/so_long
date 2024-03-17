/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:44:42 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:21:28 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	count_map(t_data *data, char ecp)
{
	int	i;
	int	j;
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
					data->pos_px = i;
					data->pos_py = j;
				}
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	control_pec(t_data *data)
{
	int	i;
	int	j;
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

int	control_ecp(t_data *data, char ecp)
{
	int	count;

	count = count_map(data, ecp);
	if (ecp == 'E' || ecp == 'P')
		if (count != 1)
			return (-1);
	if (ecp == 'C')
		if (count < 1)
			return (-1);
	return (0);
}

int	flood_map(char **map, int x, int y)
{
	if (map[x][y] == 'X' || map[x][y] == '1' )
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
	if (control_ecp(data, 'E') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_ecp(data, 'C') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_ecp(data, 'P') == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_line(data->map) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_wall(data) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	if (control_carac(data) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	flood_map(data->ctrl_map, data->pos_px, data->pos_py);
	if (control_pec(data) == -1)
		return (ft_freedouble(data->map, data->ctrl_map), -1);
	return (ft_freeall(data->ctrl_map, ft_count_path(data->map)), 0);
}
