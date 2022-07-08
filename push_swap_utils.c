/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:40:28 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/08 17:43:15 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(t_stk *stk_a, t_stk *stk_b)
{
	stk_b->len = 0;
	stk_b->stk = (int *)malloc(sizeof(int) * stk_a->len);
}

int	stack_is_sort(t_stk *stk)
{
	int	i;
	int	j;

	i = stk->len;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stk->stk[j] < stk->stk[i])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

int	is_not_duplicate(t_stk *stk)
{
	int	n;
	int	m;
	int	tmp;

	n = 0;
	while (n < stk->len)
	{
		m = n + 1;
		tmp = stk->stk[n];
		while (m < stk->len)
		{
			if (tmp == stk->stk[m])
				return (0);
			m++;
		}
		n++;
	}
	return (1);
}

int	get_maximum_number(t_stk *stk)
{
	int	n;
	int	m;
	int	max;

	n = 0;
	max = stk->stk[0];
	while (n < stk->len)
	{
		m = n;
		while (m < stk->len)
		{
			if (stk->stk[m] > max)
				max = stk->stk[m];
			m++;
		}
		n++;
	}
	return (max);
}

int	get_smallest_step_medium(t_stk *stk)
{
	int	n;
	int	hold_top;

	n = 0;
	hold_top = stk->stk[stk->len - 1];
	while (n < stk->len)
	{
		if (stk->stk[n] > hold_top)
			hold_top = stk->stk[n];
		n++;
	}
	return (get_number_index(stk, hold_top));
}
