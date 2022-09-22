/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:51 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/22 12:43:59 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	stk_a;
	t_stk	stk_b;

	parsing(argc, argv, &stk_a);
	if (stk_a.len == 0)
		return (0);
	if (!is_not_duplicate(&stk_a))
		handle_parse_error(&stk_a);
	init_stack(&stk_a, &stk_b);
	update_stack_data(&stk_a, &stk_b);
	get_three_biggest_nb(&stk_a);
	if (!stack_is_sort(&stk_a))
	{
		if (stk_a.len == 2 && stk_a.top > stk_a.bottom)
			stack_rotate(&stk_a, &stk_b, 'a');
		else if (stk_a.len == 3)
			sort_three_number(&stk_a, &stk_b);
		else if (stk_a.len > 3 && stk_a.len <= 5)
			sort_mini_stack(&stk_a, &stk_b);
		else
			sort_large_stack(&stk_a, &stk_b);
	}
	free_stacks(&stk_a, &stk_b);
	return (0);
}
