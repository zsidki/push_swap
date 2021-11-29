/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:07 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 07:06:12 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_x(t_stack *stack_a, t_stack *stack_b)
{
	long	tmp;

	tmp = pop(stack_a);
	if (tmp != LONG_MIN)
		push(stack_b, tmp);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_x(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_x(stack_a, stack_b);
	write(1, "pb\n", 3);
}
