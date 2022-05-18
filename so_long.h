/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:22:45 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/18 19:26:50 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "./libft/libft.h"

//IMAGE
typedef struct s_img
{
	int		w;
	int		h;
	void	*img;
}			t_img;

//MAP
typedef struct s_map
{
	int		floor;
	int		collect;
	int		door;
	int		wall;
	int		pj;
	int		col_len;
	int		row_len;
	char	*str_map;
	char	**map_split;
	void	*mlx;
	void	*mlx_win;
	int		w;
	int		h;
	t_img	img;
}			t_map;

typedef struct s_pj
{
	void	*pj_r;
	void	*pj_l;
	void	*pj_u;
	void	*pj_d;
	int		moves;

}			t_pj;

int		walls_len_ok(t_map *map);
int		verify_comps(t_map *map);
int		walls_ok(t_map *map);
void	init_map(t_map *map);
int		valid_map(char *name, t_map *map);
int		map_name(char *name);
void	print_map(t_map *map);
void	print_img(t_map *map);
char	**read_map(t_map *map, char *argv);

//BUFFER_SIZE
# define BUFFER_SIZE 1

//SPRITES
# define FLOOR		"./sprites/floor.xpm"
# define COLLECT	"./sprites/coleccionable.xpm"
# define DOOR		"./sprites/puerta.xpm"
# define WALL		"./sprites/muro.xpm"
# define PJ			"./sprites/personaje.xpm"

#endif