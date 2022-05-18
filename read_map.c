/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:07:35 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/18 19:17:08 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_map *map, char *argv)
{
	int		text_map;
	char	*aux;
	char	*concat;
/* 	int		i;
	
	i = 0; */
	text_map = open(argv, O_RDONLY);
	if (text_map == -1)
		return (0);
	concat = ft_strdup("");
	while (1)
	{
		map->str_map = get_next_line(text_map);
		if (!map->str_map)
			break ;
		aux = ft_substr(concat, 0, ft_strlen(concat));
 		free(concat);
		concat = ft_strjoin(aux, map->str_map);
		free(aux);
		free(map->str_map);
	}
	free(map->str_map);
	map->str_map = ft_substr(concat, 0, ft_strlen(concat));
	free(concat);
	map->map_split = ft_split(map->str_map, '\n');
	free(map->str_map);
/* 	while (i < 6)
	{
		printf("%s", map->map_split[i]);
		i++;
	} */
	close(text_map);
	return (map->map_split);
}
