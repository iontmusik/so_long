/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:25:41 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/18 21:22:51 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

//	printf("coco\n\n");
	i = 0;
	//map = (t_map *) malloc(sizeof(t_map));
	//map = NULL;
	if (argc == 2)
	{
		
		map.map_split = read_map(&map, argv[1]);
/* 		if (map.map_split == NULL || !valid_map(argv[1], &map))
			return (printf("mal"), 0);
		while (map.map_split[i]) */
	}
/* 			printf("%s\n", map.map_split[i++]);
		printf("hola");
		if (valid_map(argv[1], *map))
		{
			printf("quetal");
			map->mlx = mlx_init();
			map->mlx_win = mlx_new_window(map->mlx, map->row_len * 56,
					map->col_len * 56, "so_long");
			map->mlx_win = mlx_new_window(map->mlx, 1920,
					1080, "so_long");
			mlx_loop(map->mlx);
			print_map(map);
		}
	} */
/* 	i = 0;
	while (map->map_split[i])
		printf("%s\n", map->map_split[i++]); */
}