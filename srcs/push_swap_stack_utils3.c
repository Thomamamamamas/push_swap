/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/30 13:59:44 by tcasale          ###   ########.fr       */
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

void	free_stacks(t_stk *a, t_stk *b)
{
	free(a->stk);
	free(b->stk);
}

int	get_target(t_stk *stk, int nb)
{
	int	n;
	int	res;
	int	actual;
	int	last;

	n = stk->len - 1;
	res = -1;
	ft_printf("nb = %d\n", nb);
	while (n >= 0 && res == -1)
	{
		actual = stk->stk[n];
		if (n != stk->len - 1)
			last = stk->stk[n + 1];
		else
			last = stk->stk[0];
		ft_printf("n = %d\n", n);
		ft_printf("actual = %d\n", actual);
		ft_printf("last = %d\n", last);
		if (n == stk->len - 1 && actual < stk->bottom && actual > stk->top)
			res = stk->stk[n];
		else if (n > 0 && actual > last && nb < actual && nb > last)
			res = stk->stk[n];
		else if (n == 0)
			res = stk->stk[n];
		n--;
	}
	ft_printf("target = %d\n", res);
	return res;
}
