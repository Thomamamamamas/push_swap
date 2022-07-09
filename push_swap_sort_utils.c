/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/09 10:01:41 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_stack_empty_b(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->top < stk_b->top)
	{
		if (stk_a->stk[0] < stk_b->top && stk_a->stk[0] == stk_a->largest)
		{
			stack_push(stk_a, stk_b, 'a');
			stack_rotate(stk_a, stk_b, 'a');
		}
		else
		{
			if (stk_a->largest < stk_b->top)
			{
				while (stk_a->top < stk_b->top)
					stack_rotate(stk_a, stk_b, 'a');
			}
			stack_push(stk_a, stk_b, 'a');
			if (stk_b->len == 0)
				while (stk_a->top != stk_a->smallest)
					stack_reverse_rotate(stk_a, stk_b, 'a');
		}
	}
	else
		stack_push(stk_a, stk_b, 'a');
}
