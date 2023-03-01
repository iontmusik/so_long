/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:11:09 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/09/07 17:12:34 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_window(t_map *map)
{
	map->mlx_win = mlx_new_window(map->mlx, (map->row_len + 1) * 56,
			(map->col_len + 1) * 56, "so_long");
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->moves = 0;
	map->collected = 0;
	map->end_game = 0;
	put_window(map);
	print_map(map);
}

void	event_press(t_map *map)
{
	mlx_hook(map->mlx_win, 2, (1L << 0), bottom, map);
	mlx_hook(map->mlx_win, 17, 0, exit_game, map);
}

int	exit_game(t_map *map)
{
	free_map(map);
	printf(ANSI_COLOR_RED "SALIENDO DEL JUEGO!\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
	return (0);
}
