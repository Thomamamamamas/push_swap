/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:29:53 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/04 15:44:35 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	n;

	if (stack_a->len > stack_b->len)
		n = stack_a->len - 1;
	else
		n = stack_b->len - 1;
	while (n >= 0)
	{
		if (n >= stack_a->len)
			ft_printf("| ");
		else
			ft_printf("|%d", stack_a->stack[n]);
		ft_printf("          ");
		if (n >= stack_b->len)
			ft_printf("| \n");
		else
			ft_printf("|%d\n", stack_b->stack[n]);
		n--;
	}
	ft_printf("|-----------|-------\n|stack_a    |stack_b\n");
}
