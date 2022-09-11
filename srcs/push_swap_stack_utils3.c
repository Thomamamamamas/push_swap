/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/10 11:14:57 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	update_stack_data(t_stk *stk_a, t_stk *stk_b)
{
	stk_a->top = stk_a->stk[stk_a->len - 1];
	stk_a->bottom = stk_a->stk[0];
	stk_a->min = get_smallest(stk_a);
	stk_a->max = get_largest(stk_a);
	stk_b->top = stk_b->stk[stk_b->len - 1];
	stk_b->bottom = stk_b->stk[0];
	stk_b->min = get_smallest(stk_b);
	stk_b->max = get_largest(stk_b);
}

int	get_smallest_target(t_stk *stk, int nb, int actual)
{
	int	n;

	n = stk->len - 1;
	while (n > 0)
	{
		if (stk->stk[n] > actual && stk->stk[n] < nb)
			actual = stk->stk[n];
		n--;
	}
	return (actual);
}

int	get_target(t_stk *stk, int nb)
{
	int	n;
	int	actual;
	int	last;

	n = stk->len - 1;
	while (n >= 0)
	{
		actual = stk->stk[n];
		if (n != stk->len - 1)
			last = stk->stk[n + 1];
		else
			last = stk->stk[0];
		if (nb < get_smallest(stk))
			return (get_largest(stk));
		else if (nb > get_largest(stk))
			return (get_largest(stk));
		else if (n > 0 && actual < last && nb > actual && nb < last)
			return (get_smallest_target(stk, nb, stk->stk[n]));
		n--;
	}
	return (stk->stk[stk->len - 1]);
}

void	push_to_a_sorted(t_stk *a, t_stk *b)
{
	while (b->len != 0)
	{
		while (b->top != get_largest(b))
		{
			if (get_position(b, get_largest(b)) <= b->len / 2)
				stack_reverse_rotate(a, b, 'b');
			else
				stack_rotate(a, b, 'b');
		}
		stack_push(a, b, 'a');
	}
}
