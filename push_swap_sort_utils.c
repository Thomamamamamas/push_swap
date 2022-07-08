/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/08 21:55:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_stack_empty_b(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->stk[stk_a->len - 1] < stk_b->stk[stk_b->len - 1])
	{
		if (stk_a->stk[0] < stk_b->stk[stk_b->len - 1] && larger(stk_a->stk[0], stk_a))
		{
			stack_push(stk_a, stk_b, 'a');
			stack_rotate(stk_a, stk_b, 'a');
		}
		else
		{
			while (stk_a->stk[stk_a->len - 1] < stk_b->stk[stk_b->len - 1])
				stack_rotate(stk_a, stk_b, 'a');
			stack_push(stk_a, stk_b, 'a');
			if (stk_b->len == 0)
				while (!smaller(stk_a->stk[stk_a->len - 1], stk_a))
					stack_reverse_rotate(stk_a, stk_b, 'a');
		}
	}
	else
		stack_push(stk_a, stk_b, 'a');
}
