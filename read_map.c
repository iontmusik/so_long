/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:07:35 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/09/12 16:34:52 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_map(void)
{
	printf(ANSI_COLOR_RED "Error\nMAPA INVALIDO!\n");
	return (0);
}

void	read_map(t_map *map, char *argv)
{
	int		text_map;
	char	*aux;
	char	*concat;

	text_map = open(argv, O_RDONLY);
	if (text_map == -1)
		exit (error_map());
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
	map->map_split = ft_split(concat, '\n');
	free(concat);
	close(text_map);
}
