/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/22 12:48:54 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

t_lst	get_chunk(t_stk *a, t_lst *hold)
{
	t_lst	chunk;
	int		n;

	chunk.lst = (int *)malloc(sizeof(int) * 21);
	chunk.len = 0;
	n = 0;
	while (n < a->len)
	{
		if (!is_in_lst(a->stk[n], hold))
		{
			if (chunk.len < 20)
			{
				chunk.lst[chunk.len] = a->stk[n];
				chunk.len++;
			}
			else if (index_largest_nb(a->stk[n], &chunk) != -1)
				chunk.lst[index_largest_nb(a->stk[n], &chunk)] = a->stk[n];
		}
		n++;
	}
	return (chunk);
}

void	smart_rotate(t_stk *a, t_stk *b, int position)
{
	while (position < a->len - 1)
	{
		if (position <= a->len / 2)
		{
			stack_reverse_rotate(a, b, 'a');
			position--;
			if (position < 0)
				position = a->len - 1;
		}
		else
		{
			stack_rotate(a, b, 'a');
			position++;
		}
	}
}

void	smart_push_to_b(t_stk *a, t_stk *b)
{
	int	stop_it;
	int	target;

	stop_it = 0;
	target = get_target(b, a->top);
	if (b->len == 0 || (a->top < b->min && b->top == b->min))
		stop_it = 1;
	while (stop_it == 0)
	{
		if (get_position(b, target) == b->len - 1)
			stop_it = 1;
		if (stop_it == 0)
		{
			if (get_position(b, target) <= b->len / 2)
				stack_reverse_rotate(a, b, 'b');
			else
				stack_rotate(a, b, 'b');
		}
	}
	stack_push(a, b, 'b');
}
