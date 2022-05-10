# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:17:30 by jtorre-s          #+#    #+#              #
#    Updated: 2022/05/10 18:32:12 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	so_long.c init_map.c check_map.c map_ok.c print_map.c valid_map.c
		
OBJ = $(SRC:.c=.o)

NAME = so_long.a

CFLAGS =  -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		
all : $(NAME)

clean:
		/bin/rm -f $(OBJ)
	
fclean: clean
		/bin/rm -f $(NAME)
		
re: fclean all

.PHONY: all clean dclean re