/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:51 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/10 18:27:27 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map.map_split = read_map(fd, map);
/* 		if (valid_map(map, argv[1]))
		{
			print_map(&map)
		} */
	}
	int i = 0;
	while (map.map_split[i])
		printf("%s\n", map.map_split[i++]);

}
