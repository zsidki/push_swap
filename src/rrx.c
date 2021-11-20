/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:10 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/20 16:28:24 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    reverse_rotate(t_stack *stack)
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

void    rra(t_stack *a)
{
    reverse_rotate(a);
    write(1, "rra\n", 5);
}

void    rrb(t_stack *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 5);
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 5);
}
