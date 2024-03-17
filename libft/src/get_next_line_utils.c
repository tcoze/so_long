/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:08:08 by logname           #+#    #+#             */
/*   Updated: 2023/12/15 01:44:53 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bzero_gnl(char *s, size_t n)
{
	if (!s)
		return (NULL);
	while (n != 0)
	{
		n--;
		s[n] = '\0';
	}
	return (s);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*str;

	if (size != 0)
		if (((nmemb * size) / size) != nmemb)
			return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero_gnl(str, nmemb);
	return (str);
}

long int	ft_strchr_gnl(char *s, char c)
{
	long int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *buf)
{
	size_t	s1len;
	size_t	buflen;
	size_t	i;
	size_t	p;
	char	*s_out;

	i = 0;
	p = 0;
	s1len = ft_strlen_gnl(s1);
	buflen = ft_strlen_gnl(buf);
	s_out = ft_calloc_gnl(s1len + buflen + 1, 1);
	if (!s_out)
		return (free (s1), NULL);
	while (i < s1len)
	{
		s_out[i] = s1[i];
		i++;
	}
	while (p < buflen)
	{
		s_out[i + p] = buf[p];
		p++;
	}
	return (free (s1), s_out);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
