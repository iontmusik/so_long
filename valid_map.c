/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:28:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/09/12 16:40:26 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static void	init_map(t_map *map)
{
	map->floor = 0;
	map->collect = 0;
	map->door = 0;
	map->wall = 0;
	map->pj = 0;
	map->col_len = 0;
	map->row_len = 0;
}

int	check_empty_map(t_map *map)
{
	printf("caracola\n");
	if (map->map_split[0] == NULL)
	{
		return (0);
	}
	return (1);
}

int	valid_map(char *name, t_map	*map)
{
	if (!map)
		return (0);
	init_map(map);
	printf(ANSI_COLOR_BLUE "CHEQUEANDO MAPA...\n");
	if (map_name(name) && walls_ok(map) && verify_comps(map)
		&& walls_len_ok(map) && max_map(map))
	{
		printf(ANSI_COLOR_GREEN "MAPA CORRECTO!\nBUENA SUERTE...\n"
			ANSI_COLOR_YELLOW "");
		return (1);
	}
	return (0);
}
