/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:08:54 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 14:10:17 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	parse_stack(int argc, char **argv, t_stack *stack_a)
{
	int		n;
	int		m;

	stack_a->len = argc - 1;
	stack_a->stack = (int *)malloc(sizeof(int) * stack_a->len);
	n = stack_a->len;
	m = 0;
	while (n > 0)
	{
		if (arg_is_valid(argv[n]))
			stack_a->stack[m++] = ft_atoi(argv[n]);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		n--;
	}
}

int	arg_is_valid(char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (0);
		argv++;
	}
	return (1);
}
