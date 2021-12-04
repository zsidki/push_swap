/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:46 by zsidki            #+#    #+#             */
/*   Updated: 2021/12/04 02:49:02 by zsidki           ###   ########.fr       */
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

void swap(long *xp, long *yp)
{
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(long arr[], long new_arr[], int n)
{
    int i;
	int j;

	i = 0;
    while (i < n-1)
	{
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swap(&new_arr[j], &new_arr[j+1]);
			}
			j++;
		}
		i++;
	}
}

void change_stack_index(t_stack *a) {
	long *new_arr;
	int i;
	// a			= 6 2 7 1 3 5
	// new_arr		= 0 1 2 3 4 5
	// achno bghina	= 3 1 4 0 2

	// sorted a			= 4 1 5 0 2 3
	// sorted new_arr	= 3 1 4 5 0 2
	new_arr = malloc(sizeof(long) * a->capacity);
	i = 0;
	while (i < a->capacity)
	{
		new_arr[i] = i;
		i++;
	}
	bubbleSort(a->array, new_arr, a->capacity); //
	i = 0;
	while (i < a->capacity) {
		dprintf(2, "%ld ", a->array[i]);
		i++;
	}
	dprintf(2, "\n");
	i = 0;
	while (i < a->capacity) {
		dprintf(2, "%ld ", new_arr[i]);
		i++;
	}
	i = 0;
	while (i < a->capacity)
	{
		a->array[new_arr[i]] = i;
		i++;
	}
	free(new_arr);
}

void	order_radix(t_stack *a, t_stack *b)
{
	change_stack_index(a);
	sort_radix(a, b, stack_size(a));
}
