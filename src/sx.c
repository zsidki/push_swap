/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:16 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 07:06:22 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int i)
{
	long	tmp;

	if (stack_size(stack) >= 2)
	{
		tmp = peek(stack);
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
		if (i == 0)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack, int i)
{
	long	tmp;

	if (stack_size(stack) >= 2)
	{
		tmp = peek(stack);
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
		if (i == 0)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}
