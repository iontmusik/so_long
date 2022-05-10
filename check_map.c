/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:07:35 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 16:14:57 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, t_map *map)
{
	int		text_map;
	char	*aux;
	char	*concat;

	text_map = open(fd, O_RDONLY);
	if (fd == -1)
		return (0);
	concat = ft_strdup("");
	while (1)
	{
		map->str_map = get_next_line(fd);
		if (!str_map)
			break ;
		aux = concat;
		concat = ft_strjoin(aux, map->str_map);
	}
	map->str_map = concat;
	free(concat);
	free(aux);
	map->map_split = ft_split(map->str_map, "\n");
	close(fd);
	return (map->map_split);
}
