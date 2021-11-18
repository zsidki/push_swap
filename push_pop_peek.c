/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:52:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/18 18:52:41 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, long item)
{
	if (stack_is_full(stack))
		return ;
	stack -> array[++stack-> top] = item;
}

long	pop(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (LONG_MIN);
	return (stack->array[stack->top--]);
}

long	peek(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (LONG_MIN);
	return (stack -> array[stack -> top]);
}
