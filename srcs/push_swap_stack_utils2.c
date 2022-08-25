/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/25 13:01:36 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate(t_stk *stk)
{
	int	tmp;
	int	tmp2;
	int	n;

	n = stk->len - 1;
	while (n >= 0)
	{
		tmp = stk->stk[n];
		if (n != stk->len - 1)
			stk->stk[n--] = tmp2;
		if (n == stk->len - 1)
			stk->stk[n--] = stk->stk[0];
		tmp2 = tmp;
	}
}

void	rotate(t_stk *stk)
{
	int	tmp;
	int	tmp2;
	int	n;

	n = 0;
	while (n < stk->len)
	{
		tmp = stk->stk[n];
		if (n != 0)
			stk->stk[n++] = tmp2;
		else
			stk->stk[n++] = stk->stk[stk->len - 1];
		tmp2 = tmp;
	}
}

int	get_smallest(t_stk *stk)
{
	int	n;
	int	res;

	n = 0;
	res = INT_MAX;
	while (n < stk->len)
	{
		if (stk->stk[n] < res)
			res = stk->stk[n];
		n++;
	}
	return (res);
}

int	get_largest(t_stk *stk)
{
	int	n;
	int	res;

	n = 0;
	res = INT_MIN;
	while (n < stk->len)
	{
		if (stk->stk[n] > res)
			res = stk->stk[n];
		n++;
	}
	return (res);
}

void	update_stack_data(t_stk *stk_a, t_stk *stk_b)
{
	stk_a->top = stk_a->stk[stk_a->len - 1];
	stk_a->bottom = stk_a->stk[0];
	stk_a->smallest = get_smallest(stk_a);
	stk_a->largest = get_largest(stk_a);
	stk_b->top = stk_b->stk[stk_b->len - 1];
	stk_b->bottom = stk_b->stk[0];
	stk_b->smallest = get_smallest(stk_b);
	stk_b->largest = get_largest(stk_b);
}
