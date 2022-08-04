/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 17:43:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_stack_empty_b(t_stk *a, t_stk *b)
{
	if (a->top < b->top || a->bottom > b->top || a->max < b->top)
	{
		if (a->max > b->top)
		{
			while (b->top < a->bottom && b->top > a->min)
				stack_reverse_rotate(a, b, 'a');
			while (b->top > a->top)
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			if (b->len == 0 || (b->len > 0 && b->top < a->min))
			{
				while (!stack_is_sort(a))
					stack_rotate(a, b, 'a');
			}
		}
		else
		{
			while (!stack_is_sort(a))
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			stack_rotate(a, b, 'a');
		}
	}
	else
		stack_push(a, b, 'a');
}

int	medium_stack_empty_a(t_stk *a, t_stk *b)
{
	int	*hold;
	int	*chunk;
	int	len_hold;
	int	len_chunk;

	len_hold = 1;
	while (a->len != 0)
	{
		chunk = get_chunk(a, hold, len);
		len_chunk = get_chunk_len(a, hold, len);
		hold[++len_hold] = get_hold(a, hold);
	}
	free(hold);
}

int	get_hold_position(t_stk *a, int *hold)
{
	int	mid;
	int	hold_top;
	int	hold_bottom;
	int	n;
	int	m;

	mid = a->len / 2;
	n = 0;
	m = 0;
	hold_top = INT_MAX;
	hold_bottom = INT_MAX;
	while (n <= mid)
	{
		if (not_in_hold(a->stk[n]) && a->stk[n] < hold_top)
			hold_top = a->stk[n];
	}
	while (m < a->len)
	{
		if (not_in_hold(a->stk[n]) && a->stk[n] < hold_bottom)
			hold_top = a->stk[n];
		m++;
	}
	if (n < m)
		return (n);
	else
		return (m);
}
