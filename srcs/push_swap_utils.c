/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:40:28 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/21 13:10:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	init_stack(t_stk *stk_a, t_stk *stk_b)
{
	stk_b->len = 0;
	stk_b->stk = (int *)malloc(sizeof(int) * stk_a->len);
}

void	free_stacks(t_stk *a, t_stk *b)
{
	free(a->stk);
	free(b->stk);
}

int	stack_is_sort(t_stk *stk)
{
	int	i;
	int	j;

	i = stk->len - 1;
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
