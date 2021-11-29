/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:04 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/29 22:54:16 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_min_max(char *str)
{
	int			i;
	const char	*max_int = "2147483647";
	const char	*min_int = "-2147483648";
	const char	*min_max;

	i = 0;
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

void	fill_a(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;

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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack(argc - 1);
	b = create_stack(argc - 1);
	fill_a(argc, argv, a);
	if (is_sorted_stack(*a))
		exit(0);
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
	return (0);
}
