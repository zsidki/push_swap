/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:22:57 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 08:54:38 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_equal(char *s1, char *s2)
{
	int	i;
	int	len;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = -1;
	len = ft_strlen(s1);
	while (++i < len)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int	do_operations(t_stack *a, t_stack *b, char *line)
{
	if (ft_is_equal(line, "sa"))
		sa_bonus(a);
	else if (ft_is_equal(line, "sb"))
		sb_bonus(b);
	else if (ft_is_equal(line, "ss"))
		ss_bonus(a, b);
	else if (ft_is_equal(line, "pa"))
		pa_bonus(a, b);
	else if (ft_is_equal(line, "pb"))
		pb_bonus(a, b);
	else if (ft_is_equal(line, "ra"))
		ra_bonus(a);
	else if (ft_is_equal(line, "rb"))
		rb_bonus(b);
	else if (ft_is_equal(line, "rr"))
		rr_bonus(a, b);
	else if (ft_is_equal(line, "rra"))
		rra_bonus(a);
	else if (ft_is_equal(line, "rrb"))
		rrb_bonus(b);
	else if (ft_is_equal(line, "rrr"))
		rrr_bonus(a, b);
	else
		return (0);
	return (1);
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

// void	stack_display(t_stack stack)
// {
// 	int	i;

// 	i = stack.top;
// 	write(1, "******\n", 7);
// 	while (i >= 0)
// 		printf("%ld\n", stack.array[i--]);
// 	write(1, "******\n", 7);
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	size_t	len;

	a = create_stack(argc - 1);
	b = create_stack(argc - 1);
	fill_a(argc, argv, a);
	line = NULL;
	len = 0;
	while (get_next_line(&line))
	{
		if (!do_operations(a, b, line))
			error();
		if (line)
			free(line);
	}
	if (is_sorted_stack(*a) && stack_size(b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	if (line)
		free(line);
	return (0);
}
