/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:16 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/07 16:38:32 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    swap_a(t_stack *stack, int i)
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
void    swap_b(t_stack *stack, int i)
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


void    swap_s(t_stack *a, t_stack *b)
{
    swap_a(a, 1);
    swap_b(b, 1);
    printf("ss\n");
}


