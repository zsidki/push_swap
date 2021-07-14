/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:10:14 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 20:50:45 by zsidki           ###   ########.fr       */
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

int find_smallest_bigger(t_stack *a, int num)
{
    int i;
    
    i = 0;
    while (i <= a->top)
    {
        // printf("%d %d %d\n", num, a->array[a->top - i], a->top - i);
        if (num < a->array[a->top - i])
        {
            return (a->top - i); // return index
        }
        i++;
    }
    return (-1);
}

void     ft_sort_5(t_stack *a, t_stack *b)
{
    int rotation;
    int reverse;
    pb(a, b);
    pb(a, b);
    ft_sort_3(a);

    rotation = find_smallest_bigger(a, b->array[1]);
    if (rotation > a->top/2)
        rotation = (rotation - a->top/2 + 1) * -1;
    // else if (rotation > 0)
    //     rotation *= -1;
    printf("%d\n", rotation);
    reverse = rotation;
    // 0 or more rotation
    if (rotation < -1)
        while (rotation < -1) {
            ra(a);
            rotation++;
        }
    printf("%d\n", rotation);
    if (rotation > 0)
        while (rotation) {
            rra(a);
            rotation--;
        }
    // pa(a, b);
    // while (reverse > 0 || reverse <= -1)
    // {
    //     if (reverse++ <= -1)
    //         rra(a);
    //     else if (reverse-- > 0)
    //         ra(a);
    // }
    
}

/*
x
y
z w

6 / 2 = 3
4 > 3

4  - 3 + 1 = 2

2
6
9 1 3 7 10


2
6
9 1

6
9
2 3

9
2
6 7


2
6
9 10


1
pa

2
ra
pa
rra

3
rra
pa
ra
ra

4
pa
ra

5
rra
rra
pa
ra
ra
ra


stack A : 2 5 4 1 3
min1 = 1
if (pos[min1] < size_a/2)
-> ra ->> min1 (pos = top) -> pb
else
-> rra ->> min1 (pos = top) -> pb

sort_3num

pa
pa

*/