/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:16:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 15:24:25 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
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
void    sa(t_stack *stack, int i);
void    sb(t_stack *stack, int i);
void    ss(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void     ft_sort_3(t_stack *a);

#endif