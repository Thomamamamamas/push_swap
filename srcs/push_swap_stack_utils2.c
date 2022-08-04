/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:31:28 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

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

int	get_min(t_stk *stk)
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

int	get_max(t_stk *stk)
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

void	update_stack_data(t_stk *a, t_stk *b)
{
	a->top = a->stk[a->len - 1];
	a->bottom = a->stk[0];
	a->min = get_min(a);
	a->max = get_max(a);
	b->top = b->stk[b->len - 1];
	b->bottom = b->stk[0];
	b->min = get_min(b);
	b->max = get_max(b);
}
