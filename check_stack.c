/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:50:07 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 07:06:24 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_full(t_stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}

int	is_sorted_stack(t_stack stack)
{
	int	i;

	i = -1;
	if (stack.top < 0)
		return (0);
	while (++i < stack.top)
	{
		if (stack.array[i] < stack.array[i + 1])
			return (0);
	}
	return (1);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[i - 1] == '-' || str[i - 1] == '+')
		return (0);
	return (1);
}

void	error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}
