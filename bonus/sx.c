/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:16 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/23 21:06:19 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_stack *stack)
{
	long	tmp;

	if (stack_size(stack) >= 2)
	{
		tmp = peek(stack);
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
	}
}

void	sb_bonus(t_stack *stack)
{
	long	tmp;

	if (stack_size(stack) >= 2)
	{
		tmp = peek(stack);
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
	}
}

void	ss_bonus(t_stack *a, t_stack *b)
{
	sa_bonus(a);
	sb_bonus(b);
}
