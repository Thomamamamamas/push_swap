/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:40:28 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 17:35:23 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->len = 0;
	stack_b->stack = (int *)malloc(sizeof(int) * stack_a->len);
}

int		stack_is_sort(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->len;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stack->stack[j] < stack->stack[i])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}
