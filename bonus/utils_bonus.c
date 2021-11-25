/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:32:13 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/25 14:56:28 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_min_max(char *str)
{
	const char	*max_int = "2147483647";
	const char	*min_int = "-2147483648";
	const char	*min_max;
	int			i;

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
