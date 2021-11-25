/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:13 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/23 20:11:07 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate_bonus(t_stack *stack)
{
	long	tmp;
	int		j;

	tmp = peek(stack);
	j = stack->top;
	while (j > 0)
	{
		stack->array[j] = stack->array[j - 1];
		j--;
	}
	stack->array[0] = tmp;
}

void	ra_bonus(t_stack *a)
{
	rotate_bonus(a);
}

void	rb_bonus(t_stack *b)
{
	rotate_bonus(b);
}

void	rr_bonus(t_stack *a, t_stack *b)
{
	rotate_bonus(a);
	rotate_bonus(b);
}
