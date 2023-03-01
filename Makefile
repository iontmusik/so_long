# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2022/09/20 13:04:25 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

XPM_DIR = ./sprites

CFLAGS =  -Wall -Wextra -Werror

SRC = so_long.c read_map.c get_next_line.c get_next_line_utils.c free_game.c \
		directions.c map_ok.c pj_press_move.c print_map.c start_game.c \
		valid_map.c	

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ./libft -l ft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all : $(NAME)

run:
	./$(NAME) "map.ber"

clean:
		/bin/rm -f $(OBJ)
	
fclean: clean
		make -C $(LIBFT_DIR) fclean
		/bin/rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re