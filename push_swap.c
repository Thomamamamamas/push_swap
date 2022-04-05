/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:51 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 18:07:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	parse_stack(argc, argv, &stack_a);
	init_stack(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	if (!stack_is_sort(&stack_a))
	{
		if (stack_a.len <= 3)
			sort_three_number(&stack_a, &stack_b);
		if (stack_a.len > 3 && stack_a.len <= 5)
			sort_mini_stack(&stack_a, &stack_b);
		else if (stack_a.len > 5 && stack_a.len <= 100)
			sort_mini_stack(&stack_a, &stack_b);
		else if (stack_a.len > 100 && stack_a.len <= 500)
			sort_mini_stack(&stack_a, &stack_b);
	}
	print_stacks(&stack_a, &stack_b);
	return (0);
}
