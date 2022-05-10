/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:03:10 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 15:06:53 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->floor = 0;
	map->collect = 0;
	map->door = 0;
	map->wall = 0;
	map->pj = 0;
	map->col_len = 0;
	map->row_len = 0;
}
