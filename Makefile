# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 18:54:19 by zsidki            #+#    #+#              #
#    Updated: 2021/11/18 18:54:10 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = push_swap
CC = gcc -g #-fsanitize=address
FLAGS = -Wall -Werror -Wextra

SRC = 	stack.c push_swap.c src/sx.c push_pop_peek.c check_stack.c src/rx.c src/rrx.c src/px.c sort.c \
		


all: $(NAME)
$(NAME): $(SRC)
	make -C libft/ all
	@$(CC) -I. $(FLAGS) $(SRC) libft/libft.a -o $(NAME)

clean:
	make -C libft/ clean
	@rm -rf $(NAME)

fclean: clean
	make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean 
	@make all

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main