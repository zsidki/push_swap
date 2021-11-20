/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:32:13 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/20 15:26:26 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

struct	s_stack	*create_stack(unsigned capacity)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = malloc(stack -> capacity * sizeof(long));
	return (stack);
}

void	fill_a(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;
	
	if (argc ==  1)
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

int	stack_size(t_stack *stack)
{
	return (stack->top + 1);
}

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

int	stack_is_full(t_stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}

void	check_min_max(char *str)
{
	int	i;

	i = 0;
	const char	*max_int = "2147483647";
	const char	*min_int = "-2147483648";
	const char	*min_max;

	if (ft_strlen(str) > 11 || (ft_strlen(str) == 11
			&& str[0] != '-' && str[0] != '+'))
		error();
	if (ft_strlen(str) >= 10)
	{
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