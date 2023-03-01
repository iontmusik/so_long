/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:25:41 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/09/26 17:49:19 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		read_map(&map, argv[1]);
		if (map.map_split[0] == NULL)
			exit (error_map());
		if (valid_map(argv[1], &map))
		{
			start_game(&map);
			event_press(&map);
			mlx_loop(map.mlx);
		}
		else
		{
			printf(ANSI_COLOR_RED "Error\nMAPA INVALIDO\n");
			exit (1);
		}	
	}
	else
	{
		printf(ANSI_COLOR_RED "Error\nARGUMENTOS INVALIDOS\n");
		return (0);
	}
}
