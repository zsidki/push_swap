# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 18:54:19 by zsidki            #+#    #+#              #
#    Updated: 2021/11/20 18:40:45 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = push_swap 
BONUS = checker
CC = gcc -g #-fsanitize=address
FLAGS = -Wall -Werror -Wextra

SRC = 	stack.c radix.c find_index.c push_swap.c src/sx.c push_pop_peek.c check_stack.c src/rx.c src/rrx.c src/px.c sort.c
SRC_B  = bonus/checker.c bonus/utils_bonus.c bonus/sx.c bonus/px.c bonus/rrx.c bonus/rx.c bonus/get_next_line.c

all: $(NAME)
$(NAME): $(SRC)
	make -C libft/ all
	@$(CC) -I. $(FLAGS) $(SRC) libft/libft.a -o $(NAME)

bonus: $(BONUS)
$(BONUS): $(SRC_B)
	make -C libft/ all
	@$(CC) -I. $(FLAGS) $(SRC_B) libft/libft.a -o $(BONUS)

clean:
	make -C libft/ clean
	@rm -rf $(NAME) $(BONUS)

fclean: clean
	make -C libft/ fclean
	@rm -rf $(NAME) $(BONUS)

re: fclean 
	@make all bonus

push:
	@git add .
	@git commit -m "$(m)"
	@git push origin main
	
