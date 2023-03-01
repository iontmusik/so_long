/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_press_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:27:27 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/31 16:18:08 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	right(t_map *map)
{
	if (map->map_split[map->h][map->w + 1] != 1)
	{
		if (map->map_split[map->h][map->w + 1] == '0')
			swap_image_r(map);
		else if (map->map_split[map->h][map->w + 1] == 'C')
		{
			map->collected++;
			if (map->collected == 1)
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETO, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
			else
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETOS, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
			swap_image_r(map);
		}
		else if (map->map_split[map->h][map->w + 1] == 'E')
			if (map->collect == map->collected)
				swap_image_r(map);
	}
}

static void	left(t_map *map)
{
	if (map->map_split[map->h][map->w - 1] != 1)
	{
		if (map->map_split[map->h][map->w - 1] == '0')
			swap_image_l(map);
		else if (map->map_split[map->h][map->w - 1] == 'C')
		{
			swap_image_l(map);
			map->collected++;
			if (map->collected == 1)
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETO, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
			else
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETOS, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
		}
		else if (map->map_split[map->h][map->w - 1] == 'E')
			if (map->collect == map->collected)
				swap_image_l(map);
	}
}

static void	up(t_map *map)
{
	if (map->map_split[map->h - 1][map->w] != 1)
	{
		if (map->map_split[map->h - 1][map->w] == '0')
			swap_image_u(map);
		else if (map->map_split[map->h - 1][map->w] == 'C')
		{
			swap_image_u(map);
			map->collected++;
			if (map->collected == 1)
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETO, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
			else
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETOS, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
		}
		else if (map->map_split[map->h - 1][map->w] == 'E')
			if (map->collect == map->collected)
				swap_image_u(map);
	}
}

static void	down(t_map *map)
{
	if (map->map_split[map->h + 1][map->w] != 1)
	{
		if (map->map_split[map->h + 1][map->w] == '0')
			swap_image_d(map);
		else if (map->map_split[map->h + 1][map->w] == 'C')
		{
			swap_image_d(map);
			map->collected++;
			if (map->collected == 1)
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETO, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
			else
				printf(ANSI_COLOR_GREEN "YA TIENES %d OBJETOS, TE QUEDAN %d \n",
					map->collected, map->collect - map->collected);
		}
		else if (map->map_split[map->h + 1][map->w] == 'E')
		{
			if (map->collect == map->collected)
				swap_image_d(map);
		}
	}
}

int	bottom(int keycode, t_map *map)
{
	if (keycode == 53)
		exit_game(map);
	if (keycode == D || keycode == RIGHT)
		right(map);
	else if (keycode == A || keycode == LEFT)
		left(map);
	else if (keycode == W || keycode == UP)
		up(map);
	else if (keycode == S || keycode == DOWN)
		down(map);
	print_map(map);
	if (map->end_game == 1)
		exit_game(map);
	return (0);
}
