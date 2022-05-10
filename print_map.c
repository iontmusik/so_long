/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:12:49 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 18:19:59 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**print_map(t_map *map)
{
	map->h = -1;
	while (all_map[++map->h])
	{
		map->w = -1;
		while (all_map[map->h][++map->w])
		{
			if (all_map[map->h][map->w] == 'P')
				map->img.img = mlx_xpm_file_to_image(
						map->mlx, PJ, &map->img.w, &map->img.h);
			if (all_map[map->h][map->w] == '1')
				map->img.img = mlx_xpm_file_to_image(
						map->mlx, WALL, &map->img.w, &map->img.h);
			if (all_map[map->h][map->w] == 'E')
				map->img.img = mlx_xpm_file_to_image(
						map->mlx, DOOR, &map->img.w, &map->img.h);
			if (all_map[map->h][map->w] == 'C')
				map->img.img = mlx_xpm_file_to_image(
						map->mlx, COLLECT, &map->img.w, &map->img.h);
			if (all_map[map->h][map->w] == '0')
				map->img.img = mlx_xpm_file_to_image(
						map->mlx, FLOOR, &map->img.w, &map->img.h);
			print_img(map);
		}
	}
}

void	print_img(t_map *map)
{
	mlx_put_image_to_window(
		map->mlx, map->mlx_win, map->img.img, map->img.h, map->img.w);
	mlx_destroy_image(map->img.img);
}
