/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:48 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/13 17:25:48 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

int	count_collec(t_data *data)
{
	int i;
	int j;

	i = 0;
	data->collectable = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				data->collectable++;
			j++;
		}
		i++;
	}
	return (0);
}

static char	**ft_fill_map (char *argv, int i, char **map)
{
	int	fd;
	int	y;

	y = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (1 + i));
	if (map == NULL)
		return (NULL);
	while (y < i)
	{
		map[y] = get_next_line(fd);
		y++;
	}
	map[y] = NULL;
	if (close(fd) == -1)
		return (ft_freeall(map, ft_count_path(map)), NULL);
	return (map);
}

int	ft_check_argc(int argc, char **argv, t_data *data)
{
	char 	*line;
	int		fd;
	int 	i;

	i = 0;
	if (argc != 2)
		return (-1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL) // ADHVASDVADVJHASHVADJHA CA MARCHE PAS
		return (-1);
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
	if (close(fd) == -1)
		return (-1);
	data->x_max = i - 1;
	data->ctrl_map = ft_fill_map(argv[1], i, data->ctrl_map);
	if (data->ctrl_map == NULL)
		return (-1);
	data->map = ft_fill_map(argv[1], i, data->map);
	if (data->map == NULL)
		return (-1);
	return (0);
}