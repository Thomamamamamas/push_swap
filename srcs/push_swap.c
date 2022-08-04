/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:51 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:29:37 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	a;
	t_stk	b;

	parse_stack(argc, argv, &a);
	if (a.len == 0)
		return (0);
	if (!is_not_duplicate(&a))
		handle_parsing_error(&a);
	init_stack(&a, &b);
	update_stack_data(&a, &b);
	print_stacks(&a, &b);
	if (!stack_is_sort(&a))
	{
		if (a.len == 2)
		{
			if (a.top > a.stk[0])
				stack_rotate(&a, &b, 'a');
		}
		else if (a.len == 3)
			sort_three_number(&a, &b);
		else if (a.len > 3 && a.len <= 5)
			sort_mini_stack(&a, &b);
		else if (a.len > 5 && a.len <= 100)
			sort_medium_stack(&a, &b);
		else if (a.len > 100 && a.len <= 500)
			sort_large_stack(&a, &b);
	}
	print_stacks(&a, &b);
	ft_printf("La stack est triée : %d\n", stack_is_sort(&a));
	return (0);
}
