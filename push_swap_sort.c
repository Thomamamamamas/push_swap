/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 18:10:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three_number(t_stack *stack_a, t_stack *stack_b)
{
	if (is_smallest(stack_a->stack[1], stack_a) && is_largest(stack_a->stack[0], stack_a))
		stack_swap(stack_a, stack_b, 'a');
	else if (is_smallest(stack_a->stack[0], stack_a) && is_largest(stack_a->stack[2], stack_a))
	{
		stack_swap(stack_a, stack_b, 'a');
		print_stacks(stack_a, stack_b);
		stack_reverse_rotate(stack_a, stack_b, 'a');
	}
	else if (is_smallest(stack_a->stack[1], stack_a) && is_largest(stack_a->stack[2], stack_a))
		stack_rotate(stack_a, stack_b, 'a');
	else if (is_smallest(stack_a->stack[2], stack_a) && is_largest(stack_a->stack[1], stack_a))
	{
		stack_swap(stack_a, stack_b, 'a');
		print_stacks(stack_a, stack_b);
		stack_rotate(stack_a, stack_b, 'a');
	}
	else if (is_smallest(stack_a->stack[0], stack_a) && is_largest(stack_a->stack[1], stack_a))
		stack_reverse_rotate(stack_a, stack_b, 'a');
}

void	sort_mini_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b, 'b');
	print_stacks(stack_a, stack_b);
	if (stack_a->len > 3)
	{
		stack_push(stack_a, stack_b, 'b');
		print_stacks(stack_a, stack_b);
	}
	sort_three_number(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	stack_push(stack_a, stack_b, 'a');
	print_stacks(stack_a, stack_b);
	if (stack_a->stack[stack_a->len - 1] > stack_a->stack[stack_a->len - 2])
	{
		stack_rotate(stack_a, stack_b, 'a');
		print_stacks(stack_a, stack_b);
	}
	if (stack_b->len == 1)
	{
		stack_push(stack_a, stack_b, 'a');
		print_stacks(stack_a, stack_b);
	}
}

void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b, 'b');
	stack_push(stack_a, stack_b, 'b');
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b, 'b');
	stack_push(stack_a, stack_b, 'b');
}
