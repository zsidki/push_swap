/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:10:14 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 15:25:49 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void     ft_sort_3(t_stack *a)
{
    if(a->array[0] > a->array[2] && a->array[2] > a->array[1] )
    {
        sa(a, 0);
    }
    if(a->array[0] < a->array[1] && a->array[1] < a->array[2] )
    {
        sa(a, 0);
        rra(a);
    }
    if(a->array[0] < a->array[2] && a->array[0] > a->array[1] )
    {
        ra(a);
    }
    if(a->array[0] < a->array[1] && a->array[0] > a->array[2] )
    {
        sa(a, 0);
        ra(a);
    }
    if(a->array[0] < a->array[1] && a->array[1] > a->array[2] )
    {
        rra(a);
    }
}
