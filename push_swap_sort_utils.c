/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/11 16:51:07 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_stack_empty_b(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->top < stk_b->top)
	{
		if (stk_a->bottom < stk_b->top && stk_a->bottom == stk_a->largest)
		{
			stack_push(stk_a, stk_b, 'a');
			stack_rotate(stk_a, stk_b, 'a');
		}
		else
		{
			if (stk_a->largest < stk_b->top)
			{
				while (stk_a->top < stk_b->top && stk_a->largest != stk_a->top && stk_b->largest != stk_b->top)
					stack_rotate(stk_a, stk_b, 'a');
				while (stk_a->top < stk_b->top && stk_a->smallest != stk_a->top && stk_b->largest == stk_b->top)
					stack_rotate(stk_a, stk_b, 'a');
			}
			else
				while (stk_a->top < stk_b->top && stk_a->largest != stk_a->top)
					stack_rotate(stk_a, stk_b, 'a');
			stack_push(stk_a, stk_b, 'a');
			while (stk_a->top != stk_a->smallest && stk_b->len == 0)
				stack_rotate(stk_a, stk_b, 'a');
		}
	}
	else
		stack_push(stk_a, stk_b, 'a');
}

void	smart_fill_stack_b(t_stk *stk_a, t_stk *stk_b)
{
	while (!stack_is_sorted(stk_a))
	{
		while (stk_a->top > stk_a->bottom && keep_in_stack_a(stk_a))
		{
			stack_rotate(stk_a, stk_b, 'a');
			print_stacks(stk_a, stk_b);
		}
		while (stk_a->top > stk_a->stk[stk_a->len - 2] || !keep_in_stack_a(stk_a))
		{
			stack_push(stk_a, stk_b, 'b');
			print_stacks(stk_a, stk_b);
		}
	}
}

int	keep_in_stack_a(t_stk *stk_a)
{
	if (stk_a->top == stk_a->largest || stk_a->top > stk_a->stk[stk_a->len - 2])
	{
		return (0);
	}
	else if (stk_a->top < stk_a->bottom)
		return (0);
	return (1);
}
