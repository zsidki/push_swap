/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:07 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/19 21:37:00 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void    push_x_bonus(t_stack *stack_a, t_stack *stack_b)
{
    long tmp;
    
    tmp = pop(stack_a);
    if(tmp != LONG_MIN)
    push(stack_b, tmp);
}

void    pa_bonus(t_stack *stack_a, t_stack *stack_b)
{
    push_x_bonus(stack_b, stack_a);
}

void    pb_bonus(t_stack *stack_a, t_stack *stack_b)
{
    push_x_bonus(stack_a, stack_b);
}
