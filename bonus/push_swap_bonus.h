/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:14:29 by zsidki            #+#    #+#             */
/*   Updated: 2021/11/27 07:05:48 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int		top;
	int		capacity;
	long	*array;
}	t_stack;

int				get_next_line(char **line);
void			sa_bonus(t_stack *stack);
void			sb_bonus(t_stack *stack);
void			ss_bonus(t_stack *a, t_stack *b);
void			ra_bonus(t_stack *a);
void			rb_bonus(t_stack *b);
void			rr_bonus(t_stack *a, t_stack *b);
void			rra_bonus(t_stack *a);
void			rrb_bonus(t_stack *b);
void			rrr_bonus(t_stack *a, t_stack *b);
void			pa_bonus(t_stack *stack_a, t_stack *stack_b);
void			pb_bonus(t_stack *stack_a, t_stack *stack_b);
int				check_num(char *str);
void			check_min_max(char *str);
void			push(t_stack *stack, long item);
long			pop(t_stack *stack);
long			peek(t_stack *stack);
void			error(void);
int				stack_size(t_stack *stack);
struct	s_stack	*create_stack(unsigned int capacity);
void			fill_a(int argc, char **argv, t_stack *a);
int				stack_is_empty(t_stack *stack);
int				stack_is_full(t_stack *stack);
void			check_min_max(char *str);

#endif