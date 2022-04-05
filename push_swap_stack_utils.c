/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:21:24 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 17:57:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stack_swap(t_stack *stack_a, t_stack *stack_b, int mode)
{
	int	tmp;

	if ((mode == 'a' || mode == 's') && stack_a->len >= 2)
	{
		tmp = stack_a->stack[stack_a->len - 1];
		stack_a->stack[stack_a->len - 1] = stack_a->stack[stack_a->len - 2];
		stack_a->stack[stack_a->len - 2] = tmp;
	}
	if ((mode == 'b' || mode == 's') && stack_b->len >= 2)
	{
		tmp = stack_b->stack[stack_b->len - 1];
		stack_b->stack[stack_b->len - 1] = stack_b->stack[stack_b->len - 2];
		stack_b->stack[stack_b->len - 2] = tmp;
	}
	ft_printf("s%c\n", mode);
}

void	stack_push(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if (mode == 'a' && stack_b->len >= 1)
		stack_a->stack[stack_a->len++] = stack_b->stack[--stack_b->len];
	else if (mode == 'b' && stack_a->len >= 1)
		stack_b->stack[stack_b->len++] = stack_a->stack[--stack_a->len];
	ft_printf("p%c\n", mode);
}

void	stack_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if ((mode == 'a' || mode == 'r') && stack_a->len >= 2)
		reverse_rotate(stack_a);
	if ((mode == 'b' || mode == 'r') && stack_b->len >= 2)
		reverse_rotate(stack_b);
	ft_printf("rr%c\n", mode);
}

void	stack_rotate(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if ((mode == 'a' || mode == 'r') && stack_a->len >= 2)
		rotate(stack_a);
	if ((mode == 'b' || mode == 'r') && stack_b->len >= 2)
		rotate(stack_b);
	ft_printf("r%c\n", mode);
}
