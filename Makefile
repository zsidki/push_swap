# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 18:54:19 by zsidki            #+#    #+#              #
#    Updated: 2021/06/24 18:54:22 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = push_swap
CC = gcc -g #-fsanitize=address
FLAGS = -Wall -Werror -Wextra -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC = 		main.c \


all: $(NAME)
$(NAME): $(SRC)
	@cd libft ; make ; cd ..
	@$(CC) -I. $(FLAGS) libft/libft.a $(SRC) -o $(NAME)

clean:
	@cd libft ; make clean ; cd ..
	@rm -rf $(NAME)

fclean: clean
	@cd libft ; make fclean ; cd ..
	@rm -rf $(NAME)

re: fclean 
	@make all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main