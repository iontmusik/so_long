/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:22:45 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/09/07 17:21:44 by jtorre-s         ###   ########.fr       */
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
	int		moves;
	int		collected;
	int		end_game;
	t_img	img;
}			t_map;

//GAME FUNCTIONS

//READ MAP
void	read_map(t_map *map, char *argv);

//VERIFY MAP
int		error_map(void);
int		walls_len_ok(t_map *map);
int		verify_comps(t_map *map);
int		walls_ok(t_map *map);
int		valid_map(char *name, t_map *map);
int		map_name(char *name);
int		max_map(t_map *map);

//PRINT MAP
void	print_map(t_map *map);

//INIT AND EXIT GAME
void	start_game(t_map *map);
void	event_press(t_map *map);
int		exit_game(t_map *map);

//PLAYER MOVEMENT
int		bottom(int keycode, t_map *t_map);
void	swap_image_u(t_map *map);
void	swap_image_d(t_map *map);
void	swap_image_r(t_map *map);
void	swap_image_l(t_map *map);

//FREE
void	free_map(t_map *map);

//BUFFER_SIZE
# define BUFFER_SIZE 1

//SPRITES
# define FLOOR		"./sprites/floor.xpm"
# define COLLECT	"./sprites/coleccionable.xpm"
# define DOOR		"./sprites/puerta.xpm"
# define WALL		"./sprites/muro.xpm"
# define PJ			"./sprites/personaje.xpm"

//COLORES TEXTO
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

//MOVEMENTS
# define W	13
# define A	0
# define S	1
# define D	2

# define UP		126
# define LEFT	123
# define DOWN	125
# define RIGHT	124

#endif