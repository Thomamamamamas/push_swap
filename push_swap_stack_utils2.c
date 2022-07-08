/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/08 17:42:36 by tcasale          ###   ########.fr       */
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

int	smaller(int nb, t_stk *stk)
{
	int	n;

	n = 0;
	while (n < stk->len)
	{
		if (stk->stk[n] < nb)
			return (0);
		n++;
	}
	return (1);
}

int	larger(int nb, t_stk *stk)
{
	int	n;

	n = 0;
	while (n < stk->len)
	{
		if (stk->stk[n] > nb)
			return (0);
		n++;
	}
	return (1);
}
