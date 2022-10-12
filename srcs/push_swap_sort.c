/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/10/12 16:08:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	sort_three_number(t_stk *a, t_stk *b)
{
	if (a->stk[1] == a->min && a->stk[0] == a->max)
		stack_swap(a, b, 'a');
	else if (a->stk[0] == a->min && a->stk[2] == a->max)
	{
		stack_swap(a, b, 'a');
		stack_reverse_rotate(a, b, 'a');
	}
	else if (a->stk[1] == a->min && a->stk[2] == a->max)
		stack_rotate(a, b, 'a');
	else if (a->stk[2] == a->min && a->stk[1] == a->max)
	{
		stack_swap(a, b, 'a');
		stack_rotate(a, b, 'a');
	}
	else if (a->stk[0] == a->min && a->stk[1] == a->max)
		stack_reverse_rotate(a, b, 'a');
}

void	sort_mini_stack(t_stk *a, t_stk *b)
{
	while (a->len != 3)
	{
		if (a->top == a->first || a->top == a->second || a->top == a->third)
			stack_rotate(a, b, 'a');
		else
			stack_push(a, b, 'b');
	}
	sort_three_number(a, b);
	while (b->len != 0)
	{
		if (get_smallest(b) == b->top && b->len != 1)
			stack_rotate(a, b, 'b');
		stack_push(a, b, 'a');
	}
}

void	sort_medium_stack(t_stk *a, t_stk *b)
{
	medium_stack_empty_a(a, b);
	push_to_a_sorted(a, b);
}

void	sort_large_stack(t_stk *a, t_stk *b)
{
	medium_stack_empty_a(a, b);
	push_to_a_sorted(a, b);
}
