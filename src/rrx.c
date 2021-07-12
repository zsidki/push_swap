/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:10 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 15:28:21 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    reverse_rotate(t_stack *stack)
{
    int tmp;
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
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}

