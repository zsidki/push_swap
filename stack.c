/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:51:59 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/05 15:38:10 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

struct s_stack
{
	int			top;
	int			capacity;
	int			*array;
};

struct	s_stack *create_stack(unsigned capacity)
{
	struct s_stack	*stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int *)malloc(stack -> capacity * sizeof(int));
	return (stack);
}

int	stack_is_full(struct s_stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int	stack_is_empty(struct s_stack *stack)
{
	return (stack -> top == -1);
}

void	push(struct s_stack* stack, int item)
{
	if (stack_is_full(stack))
		return ;
	stack -> array[++stack-> top] = item;
}

int	pop(struct s_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top--]);
}

int	peek(struct s_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack -> array[stack -> top]);
}

int		main()
{
	struct s_stack *stack = create_stack(1);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	printf("%d popped from stack\n", pop(stack));
	printf("top item is %d\n", peek(stack));
    return (0);
}
