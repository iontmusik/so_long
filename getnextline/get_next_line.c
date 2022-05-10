/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:52:50 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/06 14:10:36 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>*/

int	ft_strchr_gnl(char *str, int c)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen_gnl(str);
	if (!str)
		return (0);
	while (i < j)
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read(int fd, char *sta)
{
	int		buff;
	char	*str;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	buff = 1;
	while (!ft_strchr_gnl(sta, '\n') && (buff != 0))
	{
		buff = read(fd, str, BUFFER_SIZE);
		if (buff == -1)
		{
			free(str);
			return (NULL);
		}
		str[buff] = '\0';
		sta = ft_strjoin_gnl(sta, str);
	}
	free(str);
	return (sta);
}

char	*get_next_line(int fd)
{
	static char	*sta[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sta[fd] = ft_read(fd, sta[fd]);
	if (!sta[fd])
		return (NULL);
	line = ft_line(sta[fd]);
	sta[fd] = ft_save_static(sta[fd]);
	return (line);
}
