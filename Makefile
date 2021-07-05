# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 18:54:19 by zsidki            #+#    #+#              #
#    Updated: 2021/07/05 15:37:17 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = push_swap
CC = gcc  #-fsanitize=address
FLAGS = -Wall -Werror -Wextra

SRC = 	stack.c \


all: $(NAME)
$(NAME): $(SRC)
	@$(CC) -I. $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean 
	@make all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main