/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:12:49 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/31 11:41:41 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_img(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->img.img, x * 56, y * 56);
	mlx_destroy_image(map->mlx, map->img.img);
}

static void	print_map_characters(t_map *map, int i, int j)
{
	if (map->map_split[i][j] == '1')
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, WALL, &map->img.w, &map->img.h);
	if (map->map_split[i][j] == 'E')
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, DOOR, &map->img.w, &map->img.h);
	if (map->map_split[i][j] == '0')
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, FLOOR, &map->img.w, &map->img.h);
	if (map->map_split[i][j] == 'P' ||
		map->map_split[i][j] == 'C')
	{
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, FLOOR, &map->img.w, &map->img.h);
		print_img(map, j, i);
	}
	if (map->map_split[i][j] == 'P')
	{
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, PJ, &map->img.w, &map->img.h);
	}
	if (map->map_split[i][j] == 'C')
		map->img.img = mlx_xpm_file_to_image(
				map->mlx, COLLECT, &map->img.w, &map->img.h);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_split[i])
	{
		j = 0;
		while (map->map_split[i][j])
		{
			if (map->map_split[i][j] == 'P')
			{
				map->h = i;
				map->w = j;
			}
			print_map_characters(map, i, j);
			print_img(map, j, i);
			j++;
		}
		i++;
	}
}
