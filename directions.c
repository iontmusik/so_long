/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:45:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/08/30 11:36:59 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_image_u(t_map *map)
{
	map->map_split[map->h][map->w] = '0';
	if (map->map_split[map->h - 1][map->w] == 'E')
	{
		map->map_split[map->h - 1][map->w] = 'E';
		map->end_game++;
		printf(ANSI_COLOR_GREEN "\nFELICIDADES HAS TERMINADO CON... "
			ANSI_COLOR_YELLOW "");
	}
	else
		map->map_split[map->h - 1][map->w] = 'P';
	map->h = map->h - 1;
	map->moves++;
	printf(ANSI_COLOR_YELLOW "\n%d", map->moves);
	if (map->moves == 1)
		printf(ANSI_COLOR_YELLOW " MOVIMIENTO\n");
	else
		printf(ANSI_COLOR_YELLOW " MOVIMIENTOS\n");
}

void	swap_image_r(t_map *map)
{
	map->map_split[map->h][map->w] = '0';
	if (map->map_split[map->h][map->w + 1] == 'E')
	{
		map->map_split[map->h][map->w + 1] = 'E';
		map->end_game++;
		printf(ANSI_COLOR_GREEN "\nFELICIDADES HAS TERMINADO CON... "
			ANSI_COLOR_YELLOW "");
	}
	else
		map->map_split[map->h][map->w + 1] = 'P';
	map->w = map->w + 1;
	map->moves++;
	printf(ANSI_COLOR_YELLOW "\n%d", map->moves);
	if (map->moves == 1)
		printf(ANSI_COLOR_YELLOW " MOVIMIENTO\n");
	else
		printf(ANSI_COLOR_YELLOW " MOVIMIENTOS\n");
}

void	swap_image_l(t_map *map)
{
	map->map_split[map->h][map->w] = '0';
	if (map->map_split[map->h][map->w - 1] == 'E')
	{
		map->map_split[map->h][map->w - 1] = 'E';
		map->end_game++;
		printf(ANSI_COLOR_GREEN "\nFELICIDADES HAS TERMINADO CON... "
			ANSI_COLOR_YELLOW "");
	}
	else
		map->map_split[map->h][map->w - 1] = 'P';
	map->w = map->w - 1;
	map->moves++;
	printf(ANSI_COLOR_YELLOW "\n%d", map->moves);
	if (map->moves == 1)
		printf(ANSI_COLOR_YELLOW " MOVIMIENTO\n");
	else
		printf(ANSI_COLOR_YELLOW " MOVIMIENTOS\n");
}

void	swap_image_d(t_map *map)
{
	map->map_split[map->h][map->w] = '0';
	if (map->map_split[map->h + 1][map->w] == 'E')
	{
		map->map_split[map->h + 1][map->w] = 'E';
		map->end_game++;
		printf(ANSI_COLOR_GREEN "\nFELICIDADES HAS TERMINADO CON... "
			ANSI_COLOR_YELLOW "");
	}
	else
		map->map_split[map->h + 1][map->w] = 'P';
	map->h = map->h + 1;
	map->moves++;
	printf(ANSI_COLOR_YELLOW "\n%d", map->moves);
	if (map->moves == 1)
		printf(ANSI_COLOR_YELLOW " MOVIMIENTO\n");
	else
		printf(ANSI_COLOR_YELLOW " MOVIMIENTOS\n");
}
