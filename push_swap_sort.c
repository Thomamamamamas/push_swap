/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/01 17:26:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three_number(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->stk[1] == stk_a->smallest && stk_a->stk[0] == stk_a->largest)
		stack_swap(stk_a, stk_b, 'a');
	else if (stk_a->stk[0] == stk_a->smallest && stk_a->stk[2] == stk_a->largest)
	{
		stack_swap(stk_a, stk_b, 'a');
		stack_reverse_rotate(stk_a, stk_b, 'a');
	}
	else if (stk_a->stk[1] == stk_a->smallest && stk_a->stk[2] == stk_a->largest)
		stack_rotate(stk_a, stk_b, 'a');
	else if (stk_a->stk[2] == stk_a->smallest && stk_a->stk[1] == stk_a->largest)
	{
		stack_swap(stk_a, stk_b, 'a');
		stack_rotate(stk_a, stk_b, 'a');
	}
	else if (stk_a->stk[0] == stk_a->smallest && stk_a->stk[1] == stk_a->largest)
		stack_reverse_rotate(stk_a, stk_b, 'a');
}

void	sort_mini_stack(t_stk *stk_a, t_stk *stk_b)
{
	while (stk_a->len != 3)
		stack_push(stk_a, stk_b, 'b');
	sort_three_number(stk_a, stk_b);
	print_stacks(stk_a, stk_b);
	mini_stack_empty_b(stk_a, stk_b);
	if (stk_b->len == 1)
		mini_stack_empty_b(stk_a, stk_b);
	while (!stack_is_sort(stk_a))
		stack_rotate(stk_a, stk_b, 'a');
}

void	sort_medium_stack(t_stk *stk_a, t_stk *stk_b)
{
	smart_fill_stack_b(stk_a, stk_b);
	print_stacks(stk_a, stk_b);
	ft_printf("%d\n", stack_is_sort(stk_a));
}

void	sort_large_stack(t_stk *stk_a, t_stk *stk_b)
{
	stack_push(stk_a, stk_b, 'b');
	stack_push(stk_a, stk_b, 'b');
}
