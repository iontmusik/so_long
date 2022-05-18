# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2022/05/18 19:23:57 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

XPM_DIR = ./sprites

CFLAGS =  -Wall -Wextra -Werror

SRC = so_long.c read_map.c get_next_line_utils.c get_next_line.c valid_map.c map_ok.c init_map.c


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

.PHONY: all clean dclean re