/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:10 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/19 21:37:03 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void    reverse_rotate_bonus(t_stack *stack)
{
    long tmp;
    int j;

    tmp = stack->array[0];
    j = 0;
    while(j < stack->top)
    {
        stack->array[j] = stack->array[j + 1];
        j++;
    }
    stack->array[stack->top] = tmp;
}

void    rra_bonus(t_stack *a)
{
    reverse_rotate_bonus(a);
}

void    rrb_bonus(t_stack *b)
{
    reverse_rotate_bonus(b);
}

void    rrr_bonus(t_stack *a, t_stack *b)
{
    reverse_rotate_bonus(a);
    reverse_rotate_bonus(b);
}
