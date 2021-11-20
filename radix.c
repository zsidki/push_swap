/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:46 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/20 16:06:26 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_radix(t_stack *a, t_stack *b, int size) 
{
    long max_num;
    int max_bits;
    int i;
    int j;
    long num;

    i = 0;
    max_num = find_biggest_index(a);
    //printf("A %ld\n", max_num);

    max_bits = 0;
     //printf("b %d\n", max_num);
    while ((max_num >> max_bits) != 0) 
        ++max_bits;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = peek(a);
            if(((num >> i) & 1) == 1)
                ra(a);
            else pb(a, b);
            j++;
        }
        while(!stack_is_empty(b))
            pa(a, b);
        i++;
    }

}

void    order_radix(t_stack *a, t_stack *b)
{
    int i;
    long min;

    min = -find_smallest_index(a, &min);
    //printf("%ld\n", min);
    i = 0;
    while (i <= a->top) 
    {
        a->array[i] += min;
        i++;
    }
    sort_radix(a, b, stack_size(a));
    i = 0;
    while (i <= a->top) 
    {
        // printf("B %ld\n", a->array[i]);
        a->array[i] -= min;
        // printf("A %ld\n", a->array[i]);
        i++;
    }

}