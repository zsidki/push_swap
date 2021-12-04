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
		// if (is_sorted_stack(*a))
		// 	return ;
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
    int i, j;
    for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swap(&new_arr[j], &new_arr[j+1]);
			}
		}
	}
}

void print_stack(long array[], int n) {
	int i = 0;
	while (i < n)
	{
		dprintf(2, "%ld ", array[i]);
		i++;
	}
	dprintf(2, "\n");
}

void change_stack_index(t_stack *a) {
	long *new_arr;
	int i;

	new_arr = malloc(sizeof(long) * a->capacity);
	i = 0;
	while (i < a->capacity) {
		new_arr[i] = i;
		i++;
	}
	// print_stack(a->array, a->capacity);
	// print_stack(new_arr, a->capacity);
	bubbleSort(a->array, new_arr, a->capacity);
	for (int idx = 0; idx < a->capacity; idx++) {
		a->array[new_arr[idx]] = idx;
	}
	// print_stack(a->array, a->capacity);
	// print_stack(new_arr, a->capacity);
	// free(a->array);
	// a->array = new_arr;
}

void	order_radix(t_stack *a, t_stack *b)
{

	// b = NULL;
	change_stack_index(a);
	// stack_display(*a);
	sort_radix(a, b, stack_size(a));
	// for (int i = 0; i < a->capacity / 2; i++) {
	// 	swap(&a->array[i], &a->array[a->capacity - i - 1]);
	// }
	// stack_display(*a);
	// dprintf(2, "%d\n", a->top);
}
