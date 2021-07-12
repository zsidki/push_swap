/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:16 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 15:16:02 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    sa(t_stack *stack, int i)
{
    int tmp;

    if (stack_size(*stack) >= 2)
    {
    tmp = peek(stack);
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = tmp;
    if(i == 0 )
        printf("sa\n");
    }
}
void    sb(t_stack *stack, int i)
{
    int tmp;

    if (stack_size(*stack) >= 2)
    {
    tmp = peek(stack);
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = tmp;
    if(i == 0 )
        printf("sb\n");
    }
}


void    ss(t_stack *a, t_stack *b)
{
    sa(a, 1);
    sb(b, 1);
    printf("ss\n");
}


