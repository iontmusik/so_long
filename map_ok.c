/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:44:30 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/18 21:20:23 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_len_ok(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map_split[i]);
	while (map->map_split[i])
	{
		if (ft_strlen(map->map_split[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	verify_comps(t_map *map)
{
	int	col;
	int	row;

	col = -1;
	while (map->map_split[++col])
	{
		row = -1;
		while (map->map_split[col][++row])
		{
			if (map->map_split[col][row] == '0')
				map->floor++;
			else if (map->map_split[col][row] == 'C')
				map->collect++;
			else if (map->map_split[col][row] == 'E')
				map->door++;
			else if (map->map_split[col][row] == 'P')
				map->pj++;
			else if (map->map_split[col][row] != '1')
				return (0);
		}
	}
	if (map->collect > 0 && map->door > 0 && map->pj > 0)
		return (1);
	return (0);
}

int	walls_ok(t_map *map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	map->row_len = ft_strlen(*map->map_split) - 1;
	while (map->map_split[map->col_len])
		map->col_len++;
	map->col_len--;
	while (map->map_split[col])
	{
		row = 0;
		while (map->map_split[col][row])
		{
			if (map->map_split[0][row] != '1' ||
				map->map_split[map->col_len][row] != '1' ||
				map->map_split[col][0] != '1' ||
				map->map_split[col][map->row_len] != '1')
				return (printf("%c", map->map_split[0][row]), 0);
			row++;
		}
		col++;
	}
	return (1);
}

/* int	comps_ok(t_map map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (map->map_split[col])
	{
		while (map->map_split[col][row])
		{
			if (map->map_split[col][row] != '0' &&
				map->map_split[col][row] != 'C' &&
				map->map_split[col][row] != 'E' &&
				map->map_split[col][row] != 'P' &&
				map->map_split[col][row] != '1')
				return (0);
			row++;
		}
		col++;
	}
	return (0);
} */

int	map_name(char *name)
{
	char	*str;

	if (!name)
		return (0);
	str = ft_strrchr(name, '.');
	if (strcmp(str, ".ber") == 0)
		return (1);
	else
		return (0);
}
