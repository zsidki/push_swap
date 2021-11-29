/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:16:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 07:05:19 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int			top;
	int			capacity;
	long		*array;
}	t_stack;

struct	s_stack	*create_stack(unsigned int capacity);
long			find_smallest_index(t_stack *a, long *min_index);
int				stack_size(t_stack *stack);
void			stack_display(t_stack stack);
int				stack_is_full(t_stack *stack);
int				stack_is_empty(t_stack *stack);
void			push(t_stack *stack, long item);
long			pop(t_stack *stack);
long			peek(t_stack *stack);
void			sa(t_stack *stack, int i);
void			sb(t_stack *stack, int i);
void			ss(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			fill_a(int argc, char **argv, t_stack *a);
void			push_to_top(t_stack *s, int index, int nb);
void			ft_sort_3(t_stack *a);
void			ft_sort_4(t_stack *a, t_stack *b);
void			ft_sort_5(t_stack *a, t_stack *b);
void			order_radix(t_stack *a, t_stack *b);
void			ft_sort_2(t_stack *a);
void			error(void);
int				check_num(char *str);
void			check_min_max(char *str);
void			sort_radix(t_stack *a, t_stack *b, int size);
long			find_smallest_index(t_stack *a, long *min_index);
long			find_biggest_index(t_stack *a);
int				is_sorted_stack(t_stack stack);

#endif