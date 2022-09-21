/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/21 14:43:51 by tcasale          ###   ########.fr       */
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
		if (is_three_largest(a, a->top))
			stack_rotate(a, b, 'a');
		else
			stack_push(a, b, 'b');
	}
	sort_three_number(a, b);
	print_stacks(a, b);
	push_to_a_sorted(a, b);
	print_stacks(a, b);
	return ;
	while (!stack_is_sort(a))
	{
		if (get_smallest(a) <= a->len / 2)
			stack_reverse_rotate(a, b, 'a');
		else
			stack_rotate(a, b, 'a');
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
