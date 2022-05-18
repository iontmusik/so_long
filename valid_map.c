/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:28:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/18 21:14:10 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char *name, t_map	*map)
{
 	if (!map)
		return (0);
	init_map(map);
	if (walls_ok(map) 
 	&& verify_comps(map)
		&& walls_len_ok(map)
		&& map_name(name)
		)
		return (1);
	return (0);
}
