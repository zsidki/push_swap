/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:51:59 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/14 16:25:02 by zsidki           ###   ########.fr       */
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

int	stack_size(t_stack *stack)
{
	return (stack->top + 1);
}

// void	stack_display(t_stack stack)
// {
// 	int i;
// 	i = stack.top;
// 	printf("******\n");
// 	while(i >= 0)
// 		printf("%d\n", stack.array[i--]);
// 	printf("******\n");
// }

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

int		check_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void error()
{
	write(1, "Error\n", 7);
	exit(1);
}
void check_min_max(char * str)
{
	int i = 0;
	const char *max_int = "2147483647";
	const char *min_int = "-2147483648";
	const char *min_max;
	
	if (strlen(str) > 11 || (strlen(str) == 11 && str[0] != '-' && str[0] != '+'))
		error();
	if (strlen(str) >= 10) {
		if (str[0] == '-')
			min_max = min_int;
		else
			min_max = max_int;
		while (str[i])
		{
			if (str[i] > min_max[i])
				error();
			else if (str[i] < min_max[i])
				return ;
			i++;
		}
	}
}

void	fill_a(int argc, char **argv, t_stack *a)
{
	int i;
	int num;

	while(argc > 1)
	{
		i = 0;
		if(!check_num(argv[argc - 1]))
			error();
		check_min_max(argv[argc - 1]);
		num = atoi(argv[argc - 1]); // ft_
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

int		main(int argc, char *argv[])
{

	t_stack *a = create_stack(argc - 1);
	t_stack *b = create_stack(argc - 1);
	fill_a(argc, argv, a);
	if (argc == 3)
		ft_sort_2(a);
	else if (argc == 4)
		ft_sort_3(a);
	else if (argc == 5)
		ft_sort_4(a, b);
	else if (argc == 6)
		ft_sort_5(a, b);
	else if (argc > 6)
		order_radix(a, b);
	//ft_sort_5(a, b);
	//stack_display(*a);
	//stack_display(*b);
	
	return (0);
}
