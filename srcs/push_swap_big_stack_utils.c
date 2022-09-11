/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_stack_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:52 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/10 11:15:29 by tcasale          ###   ########.fr       */
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
	while (n > 0 && n < stk->len)
	{
		if (stk->stk[n] > nb)
			nb = stk->stk[n];
		if (part == 0 && n == stk->len / 2 - 1)
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
