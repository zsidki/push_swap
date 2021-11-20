/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:51:59 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/20 16:05:27 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct	s_stack	*create_stack(unsigned capacity)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = malloc(stack -> capacity * sizeof(long));
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->top + 1);
}

void	stack_display(t_stack stack)
{
	int	i;

	i = stack.top;
	printf("******\n");
	while (i >= 0)
		printf("%ld\n", stack.array[i--]);
	printf("******\n");
}
