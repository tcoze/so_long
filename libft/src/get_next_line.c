/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:04:58 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/17 22:38:35 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_next_line(int fd);
static char	*ft_str_separate(char *out, char *buff, int buffer_pb);
static char	*ft_read_and_fill(int fd, char *out, char *buff, int value_read);
static char	*ft_check_first_buff(char *out, char *buff);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*out;
	int			value_read;

	value_read = 0;
	out = ft_calloc_gnl(1, 1);
	if (!out)
		return (NULL);
	out = ft_check_first_buff(out, buff);
	if (!out)
		return (NULL);
	if (ft_strchr_gnl(out, '\n') != -1)
		return (out);
	out = ft_read_and_fill(fd, out, buff, value_read);
	if (!out)
		return (NULL);
	if (*out)
		return (out);
	return (free(out), NULL);
}

static char	*ft_str_separate(char *out, char *buff, int buffer_pb)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * buffer_pb + 2);
	if (!temp)
		return (free(out), NULL);
	while (i <= buffer_pb)
	{
		temp[i] = buff[i];
		i++;
	}
	temp[i] = '\0';
	out = ft_strjoin_gnl(out, temp);
	free(temp);
	if (!out)
		return (NULL);
	while (i < BUFFER_SIZE)
		buff[j++] = buff[i++];
	while (j < BUFFER_SIZE)
		buff[j++] = '\0';
	return (out);
}

static char	*ft_check_first_buff(char *out, char *buff)
{
	int	buffer_pb;

	buffer_pb = ft_strchr_gnl(buff, '\n');
	if (*buff && buffer_pb != -1)
	{
		out = ft_str_separate (out, buff, buffer_pb);
		if (!out)
			return (NULL);
		return (out);
	}
	if (*buff && buffer_pb == -1)
	{
		out = ft_strjoin_gnl(out, buff);
		ft_bzero_gnl(buff, BUFFER_SIZE);
		if (!out)
			return (NULL);
	}
	return (out);
}

static char	*ft_read_and_fill(int fd, char *out, char *buff, int value_read)
{
	int	buffer_pb;

	value_read = read(fd, buff, BUFFER_SIZE);
	while (value_read > 0)
	{
		buffer_pb = ft_strchr_gnl(buff, '\n');
		if (buffer_pb != -1)
		{
			out = ft_str_separate(out, buff, buffer_pb);
			if (!out)
				return (NULL);
			return (out);
		}
		else
		{
			out = ft_strjoin_gnl(out, buff);
			ft_bzero_gnl(buff, BUFFER_SIZE);
			if (!out)
				return (NULL);
		}
		value_read = read(fd, buff, BUFFER_SIZE);
	}
	if (value_read == -1)
		return (free(out), NULL);
	return (out);
}
