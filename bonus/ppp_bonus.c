/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:57:45 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/23 21:01:35 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *stack, long item)
{
	if (stack_is_full(stack))
		return ;
	stack -> array[++stack-> top] = item;
}

long	pop(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (LONG_MIN);
	return (stack->array[stack->top--]);
}

long	peek(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (LONG_MIN);
	return (stack -> array[stack -> top]);
}

void	fill_a(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;

	if (argc == 1)
		exit(0);
	while (argc > 1)
	{
		i = 0;
		if (!check_num(argv[argc - 1]))
			error();
		check_min_max(argv[argc - 1]);
		num = ft_atoi(argv[argc - 1]);
		while (i <= a->top)
		{
			if (num == a->array[i])
				error();
			i++;
		}
		push(a, num);
		argc--;
	}
}

void	error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}
