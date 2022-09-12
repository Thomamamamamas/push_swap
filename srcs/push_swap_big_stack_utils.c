/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_stack_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:52 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/12 13:55:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	get_biggest_in_partition(t_stk *stk, int part)
{
	int	n;
	int	nb;
	int	tmp;

	nb = INT_MIN;
	tmp = INT_MIN;
	if (part == 0)
		n = stk->len - 1;
	else
		n = stk->len / 2;
	while (n >= 0 && n < stk->len)
	{
		if (stk->stk[n] > nb)
			nb = stk->stk[n];
		if (part == 0 && n >= stk->len / 2 - 1)
			return (nb);
		n--;
	}
	return (nb);
}

int	get_total_move_stack(t_stk *stk, int nb)
{
	if (get_position(stk, nb) > stk->len / 2)
		return (get_position(stk, nb) - stk->len / 2);
	else
		return (get_position(stk, nb));
}

int	get_biggest_position_wanted(t_stk *stk, int nb, int actual)
{
	int	n;

	n = stk->len - 1;
	while (n > 0)
	{
		if (stk->stk[n] < actual && stk->stk [n] > nb)
			actual = stk->stk[n];
		n--;
	}
	return (actual);
}

int	get_position_wanted(t_stk *stk, int nb)
{
	int	n;
	int	actual;
	int	last;

	n = stk->len - 1;
	while (n >= 1)
	{
		actual = stk->stk[n];
		if (n != stk->len - 1)
			last = stk->stk[n + 1];
		else
			last = stk->stk[0];
		if (nb < get_smallest(stk))
			return (get_smallest(stk));
		else if (nb > get_largest(stk))
			return (get_smallest(stk));
		else if (n > 0 && actual > last && nb < actual && nb > last)
			return (get_biggest_position_wanted(stk, nb, stk->stk[n]));
		n--;
	}
	return (stk->stk[stk->len - 1]);
}

int	check_for_double_r(t_stk *a, t_stk *b, int nb, int target)
{
	if (target != a->top)
	{
		if (nb >= b->len / 2 && target >= a->len / 2)
			return (1);
		else if (nb <= b->len / 2 && target <= a->len / 2)
			return (1);
	}
	return (0);
}
