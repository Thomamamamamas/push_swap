/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:42:47 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 17:58:34 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	tmp2;
	int	n;

	n = stack->len - 1;
	while (n >= 0)
	{
		tmp = stack->stack[n];
		if (n != stack->len - 1)
			stack->stack[n--] = tmp2;
		if (n == stack->len - 1)
			stack->stack[n--] = stack->stack[0];
		tmp2 = tmp;
	}
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	tmp2;
	int	n;

	n = 0;
	while (n < stack->len)
	{
		tmp = stack->stack[n];
		if (n != 0)
			stack->stack[n++] = tmp2;
		else
			stack->stack[n++] = stack->stack[stack->len - 1];
		tmp2 = tmp;
	}
}

int	is_smallest(int nb, t_stack *stack)
{
	int	n;

	n = 0;
	while (n < stack->len)
	{
		if (stack->stack[n] < nb)
			return (0);
		n++;
	}
	return (1);
}

int	is_largest(int nb, t_stack *stack)
{
	int	n;

	n = 0;
	while (n < stack->len)
	{
		if (stack->stack[n] > nb)
			return (0);
		n++;
	}
	return (1);
}
