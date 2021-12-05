/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:46 by zsidki            #+#    #+#             */
/*   Updated: 2021/12/05 02:45:48 by zsidki           ###   ########.fr       */
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
		if (((num >> i) & 1) == 1)
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
	while ((max_num >> max_bits) != 0)
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
	change_stack_index(a);
	sort_radix(a, b, stack_size(a));
}
