/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:51 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/25 13:02:40 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	stk_a;
	t_stk	stk_b;

	parse_stack(argc, argv, &stk_a);
	if (stk_a.len == 0)
		return (0);
	if (!is_not_duplicate(&stk_a))
		handle_parsing_error(&stk_a);
	init_stack(&stk_a, &stk_b);
	update_stack_data(&stk_a, &stk_b);
	//print_stacks(&stk_a, &stk_b);
	if (!stack_is_sort(&stk_a))
	{
		if (stk_a.len == 2)
		{
			if (stk_a.top > stk_a.stk[0])
				stack_rotate(&stk_a, &stk_b, 'a');
		}
		else if (stk_a.len == 3)
			sort_three_number(&stk_a, &stk_b);
		else if (stk_a.len > 3 && stk_a.len <= 5)
			sort_mini_stack(&stk_a, &stk_b);
		else if (stk_a.len > 5 && stk_a.len <= 100)
			sort_medium_stack(&stk_a, &stk_b);
		else if (stk_a.len > 100 && stk_a.len <= 500)
			sort_large_stack(&stk_a, &stk_b);
	}
	print_stacks(&stk_a, &stk_b);
	//ft_printf("%d\n", stack_is_sort(&stk_a));
	return (0);
}
