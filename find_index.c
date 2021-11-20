/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:38 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/19 17:18:11 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long find_smallest_index(t_stack *a, long *min_index)
{
    int i;
    long min;
 
    min = a->array[0];
    i = 0;
    while (i <= a->top)
    {
        if (min > a->array[i])
            min =  a->array[i];// return index
        i++;
    }
    *min_index = i - 1;
    return (min);
}

long find_biggest_index(t_stack *a)
{
    int i;
    long max;
 
    max = a->array[0];
    i = 0;
    while (i <= a->top)
    {
        if (max < a->array[i])
            max =  a->array[i];
        i++;
    }
    return (max);
}
