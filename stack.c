/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:51:59 by zsidki            #+#    #+#             */
/*   Updated: 2021/07/12 20:27:48 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



struct	s_stack *create_stack(unsigned capacity)
{
	struct s_stack	*stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int *)malloc(stack -> capacity * sizeof(int));
	return (stack);
}

int	stack_size(t_stack stack)
{
	return (stack.top + 1);
}

void	stack_display(t_stack stack)
{
	int i;
	i = stack.top;
	printf("******\n");
	while(i >= 0)
		printf("%d\n", stack.array[i--]);
	printf("******\n");
}

int	stack_is_full(t_stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}

void	push(t_stack *stack, int item)
{
	if (stack_is_full(stack))
		return ;
	stack -> array[++stack-> top] = item;
}

int	pop(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top--]);
}

int	peek(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack -> array[stack -> top]);
}

void	fill_a(int argc, char **argv, t_stack *a)
{
	while(argc > 1)
	{
		push(a, atoi(argv[argc - 1]));
		argc--;
	}
}

int		main(int argc, char *argv[])
{

	t_stack *a = create_stack(100);
	t_stack *b = create_stack(100);
	fill_a(argc, argv, a);
	// fill_a(argc, argv, b);
	// push(a, 10);
	//printf("%d popped from stack\n", pop(a));
	// printf("top item is %d\n", peek(stack));
	// swap_a(a, 0);
	// swap_b(b, 0);
	// rra(a);
	// stack_display(*b);
	// pa(a, b);


	ft_sort_5(a, b);
	stack_display(*a);
	stack_display(*b);
	
	return (0);
}
