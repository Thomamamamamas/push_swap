/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:29:53 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:42:41 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	print_stacks(t_stk *a, t_stk *b)
{
	int	n;

	if (a->len > b->len)
		n = a->len - 1;
	else
		n = b->len - 1;
	while (n >= 0)
	{
		if (n >= a->len)
			ft_printf("| ");
		else
			ft_printf("|%-11d", a->stk[n]);
		if (n >= b->len)
			ft_printf("| \n");
		else
			ft_printf("|%d-11\n", b->stk[n]);
		n--;
	}
	ft_printf("|-----------|-----------\n|a          |b\n");
}
