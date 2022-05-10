/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:44:30 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 16:47:26 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_len_ok(char **map_split)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(*map_split);
	while (map_split[i])
	{
		if (map_split[i] != len)
			return (0);
		i++;
	}
	return (1);
}

int	verify_comps(char **map_split, t_map *map)
{
	int	col;
	int	row;

	col = -1;
	row = -1;
	while (map_split[++col])
	{
		while (map_split[col][++row])
		{
			if (map_split[col][row] == '0')
				map->floor++;
			else if (map_split[col][row] == 'C')
				map->collect++;
			else if (map_split[col][row] == 'E')
				map->door++;
			else if (map_split[col][row] == 'P')
				map->pj++;
		}
	}
	if (map->floor > 0 && map->collect > 0 && map->door > 0 && map->pj > 0)
		return (1);
	return (0);
}

int	walls_ok(char **map_split, t_map *map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	map->row_len = ft_strlen(*map_split);
	while (map_split[map->col_len])
		map->col_len++;
	map->col_len--;
	while (map_split[col])
	{
		while (map_split[col][row])
		{
			if (map_split[0][row] != 1 || map_split[map->col_len][row] != 1 ||
				map_split[col][0] != 1 || map_split[col][map->row_len] != 1)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}

int	comps_ok(char **map_split, t_map *map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (map_split[col])
	{
		while (map_split[col][row])
		{
			if (map_split[col][row] != '0' && map_split[col][row] != 'C' &&
				map_split[col][row] != 'E' && map_split[col][row] != 'P' &&
				map_split[col][row] != '1')
				return (0);
			row++;
		}
		col++;
	}
	return (0);
}

int	map_name(char *name)
{
	char	*str;

	if (!name)
		return (0);
	str = ft_strchr(name, '.'));
	if (strcmp(str, ".ber") == 0)
		return (1);
	else
		return (0);
}
