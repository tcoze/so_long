/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:12:25 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:13:35 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	control_carac(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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

int	control_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->y_max = ft_strlen(data->map[x]) - 2;
	while (y <= data->y_max && data->map[x])
	{
		if (data->map[x][y] != '1')
			return (-1);
		y++;
	}
	while (x <= data->x_max && data->map[x])
	{
		if (data->map[x][0] != '1' || data->map[x][data->y_max] != '1')
			return (-1);
		x++;
	}
	y = -1;
	x = x - 1;
	while (++y <= data->y_max && data->map[x])
		if (data->map[x][y] != '1')
			return (-1);
	return (0);
}

int	control_line(char **map)
{
	int		i;
	int		j;
	size_t	len;
	size_t	temp;

	i = 0;
	len = ft_strlen(map[0]);
	if (ft_count_path(map) < 2)
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
	if (ft_strlen(map[j]) != len - 1 && ft_strlen(map[j]) != len)
		return (-1);
	return (0);
}
