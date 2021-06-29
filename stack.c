/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:51:59 by zsidki            #+#    #+#             */
/*   Updated: 2021/06/29 19:58:36 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

struct Stack
{
	int			top;
	unsigned	capacity;
	int			*array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack*	stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int *)malloc(stack -> capacity * sizeof(int));
	return (stack);
}
