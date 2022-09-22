/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/22 12:40:32 by tcasale          ###   ########.fr       */
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

int	get_position(t_stk *stk, int nb)
{
	int	n;

	n = 0;
	while (n < stk->len && stk->stk[n] != nb)
		n++;
	return (n);
}
