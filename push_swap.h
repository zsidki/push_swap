/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:16:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/06 16:34:20 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int			top;
	int			capacity;
	int			*array;
} t_stack;


struct	s_stack *create_stack(unsigned capacity);
int	stack_size(t_stack stack);
void	stack_display(t_stack stack);
int	stack_is_full(t_stack *stack);
int	stack_is_empty(t_stack *stack);
void	push(t_stack *stack, int item);
int	pop(t_stack *stack);
int	peek(t_stack *stack);
void    swap_a(t_stack *stack, int i);
void    swap_b(t_stack *stack, int i);
void    swap_s(t_stack *a, t_stack *b);

#endif