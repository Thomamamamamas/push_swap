/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:30:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	mini_stack_empty_b(t_stk *a, t_stk *b)
{
	if (a->top < b->top || a->bottom > b->top || a->max < b->top)
	{
		if (a->max > b->top)
		{
			while (b->top < a->bottom && b->top > a->min)
				stack_reverse_rotate(a, b, 'a');
			while (b->top > a->top)
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			if (b->len == 0 || (b->len > 0 && b->top < a->min))
			{
				while (!stack_is_sort(a))
					stack_rotate(a, b, 'a');
			}
		}
		else
		{
			while (!stack_is_sort(a))
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			stack_rotate(a, b, 'a');
		}
	}
	else
		stack_push(a, b, 'a');
}

void	smart_fill_stack_b(t_stk *a, t_stk *b)
{
	while (!stack_is_sort(a))
	{
		while (a->top > a->bottom && keep_in_stack_a(a))
		{
			stack_rotate(a, b, 'a');
			print_stacks(a, b);
		}
		while (a->top > a->stk[a->len - 2] || !keep_in_stack_a(a))
		{
			stack_push(a, b, 'b');
			print_stacks(a, b);
		}
	}
}

int	keep_in_stack_a(t_stk *a)
{
	if (a->top == a->max || a->top > a->stk[a->len - 2])
	{
		return (0);
	}
	else if (a->top < a->bottom)
		return (0);
	return (1);
}
