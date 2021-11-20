/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:10:14 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/19 17:17:42 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    ft_sort_2(t_stack *a)
{
    if(a->array[0] < a->array[1] )
    {
        ra(a);
    }    
}
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

void    push_to_top(t_stack *s, int index, int nb)
{
    while(peek(s) != nb)
    {
        if (index >= stack_size(s) / 2)
            ra(s);
        else 
            rra(s);
        
    }
}

void     ft_sort_4(t_stack *a, t_stack *b)
{
    long min_index;
    long min;

    min = find_smallest_index(a, &min_index);
    push_to_top(a, min_index, min);
    // printf("t-->%d\n", min_index);
    pb(a, b);
    ft_sort_3(a);
    pa(a, b);
}

void     ft_sort_5(t_stack *a, t_stack *b)
{
    long min_index;
    long min;

    min = find_smallest_index(a, &min_index);
    push_to_top(a, min_index, min);
    pb(a, b);
    ft_sort_4(a, b);
    pa(a, b);
}
