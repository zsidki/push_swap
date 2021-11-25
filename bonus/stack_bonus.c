/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:01:47 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/23 21:03:09 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

struct	s_stack	*create_stack(unsigned int capacity)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = malloc(stack -> capacity * sizeof(long));
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->top + 1);
}

int	stack_is_full(t_stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}
