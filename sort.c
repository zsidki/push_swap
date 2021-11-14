/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:10:14 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/14 15:47:17 by zsidki           ###   ########.fr       */
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

int find_smallest_index(t_stack *a, int *min_index)
{
    int i;
    int min;
 
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

int find_biggest_index(t_stack *a)
{
    int i;
    int max;
 
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
    int min_index;
    int min;

    min = find_smallest_index(a, &min_index);
    push_to_top(a, min_index, min);
    // printf("t-->%d\n", min_index);
    pb(a, b);
    ft_sort_3(a);
    pa(a, b);
}

void     ft_sort_5(t_stack *a, t_stack *b)
{
    int min_index;
    int min;

    min = find_smallest_index(a, &min_index);
    push_to_top(a, min_index, min);
    pb(a, b);
    ft_sort_4(a, b);
    pa(a, b);
}

static void sort_radix(t_stack *a, t_stack *b, int size) 
{
    int max_num;
    int max_bits;
    int i;
    int j;
    int num;

    i = 0;
    max_num = find_biggest_index(a);
    max_bits = 0;
    // printf("b %d\n", max_num);
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
    int min;

    min = -find_smallest_index(a, &min);
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
        a->array[i] -= min;
        i++;
    }

}
