/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:38 by zsidki            #+#    #+#             */
/*   Updated: 2021/12/05 03:02:18 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_smallest_index(t_stack *a, long *min_index)
{
	int		i;
	long	min;

	min = a->array[0];
	i = 0;
	while (i <= a->top)
	{
		if (min > a->array[i])
			min = a->array[i];
		i++;
	}
	*min_index = i - 1;
	return (min);
}

long	find_biggest_index(t_stack *a)
{
	int		i;
	long	max;

	max = a->array[0];
	i = 0;
	while (i <= a->top)
	{
		if (max < a->array[i])
			max = a->array[i];
		i++;
	}
	return (max);
}

void	swap(long *xp, long *yp)
{
	long	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubblesort(long *arr, long *new_arr, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swap(&new_arr[j], &new_arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	change_stack_index(t_stack *a)
{
	long	*new_arr;
	int		i;

	new_arr = malloc(sizeof(long) * a->capacity);
	i = 0;
	while (i < a->capacity)
	{
		new_arr[i] = i;
		i++;
	}
	bubblesort(a->array, new_arr, a->capacity);
	i = 0;
	while (i < a->capacity)
	{
		a->array[new_arr[i]] = i;
		i++;
	}
	free(new_arr);
}
