/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:28:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 17:33:50 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char **map_split, char *name)
{
	t_map	*map;

	if (!map)
		return (0);
	init_map(&map);
	if (walls_ok(map_split, &map) && verify_comps(map_split, &map)
		&& walls_len_ok(map_split) && comps_ok(map_split, &map)
		&& count_collect(map_split) && map_name(name))
		return (1);
	return (0);
}
