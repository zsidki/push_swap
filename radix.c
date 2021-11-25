/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:46 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/25 15:18:23 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_first_bit(t_stack *a, t_stack *b, int size, int i)
{
	int		j;
	long	num;

	j = 0;
	while (j < size)
	{
		num = peek(a);
		if (((num >> i) & 1) == 1) //check first bit if = 1 ra if 0 send it to stack b
			ra(a);
		else
			pb(a, b);
		j++;
	}
}

void	sort_radix(t_stack *a, t_stack *b, int size)
{
	long	max_num;
	int		max_bits;
	int		i;

	i = 0;
	max_num = find_biggest_index(a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)// calcule how much bits in max numbers // shift to remove whole numbers "1" to end with
		++max_bits;
	while (i < max_bits)
	{
		if (is_sorted_stack(*a))
			return ;
		check_first_bit(a, b, size, i);
		while (!stack_is_empty(b))
			pa(a, b);
		i++;
	}
}

void	order_radix(t_stack *a, t_stack *b)
{
	int		i;
	long	min;

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
