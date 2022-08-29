/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:21:24 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/29 13:16:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	stack_swap(t_stk *stk_a, t_stk *stk_b, int mode)
{
	int	tmp;

	if ((mode == 'a' || mode == 's') && stk_a->len >= 2)
	{
		tmp = stk_a->stk[stk_a->len - 1];
		stk_a->stk[stk_a->len - 1] = stk_a->stk[stk_a->len - 2];
		stk_a->stk[stk_a->len - 2] = tmp;
	}
	if ((mode == 'b' || mode == 's') && stk_b->len >= 2)
	{
		tmp = stk_b->stk[stk_b->len - 1];
		stk_b->stk[stk_b->len - 1] = stk_b->stk[stk_b->len - 2];
		stk_b->stk[stk_b->len - 2] = tmp;
	}
	update_stack_data(stk_a, stk_b);
	ft_printf("s%c\n", mode);
}

void	stack_push(t_stk *stk_a, t_stk *stk_b, int mode)
{
	if (mode == 'a' && stk_b->len >= 1)
		stk_a->stk[stk_a->len++] = stk_b->stk[--stk_b->len];
	else if (mode == 'b' && stk_a->len >= 1)
		stk_b->stk[stk_b->len++] = stk_a->stk[--stk_a->len];
	update_stack_data(stk_a, stk_b);
	ft_printf("p%c\n", mode);
}

void	stack_reverse_rotate(t_stk *stk_a, t_stk *stk_b, int mode)
{
	if ((mode == 'a' || mode == 'r') && stk_a->len >= 2)
	{
		reverse_rotate(stk_a);
	}
	if ((mode == 'b' || mode == 'r') && stk_b->len >= 2)
		reverse_rotate(stk_b);
	update_stack_data(stk_a, stk_b);
	ft_printf("rr%c\n", mode);
}

void	stack_rotate(t_stk *stk_a, t_stk *stk_b, int mode)
{
	if ((mode == 'a' || mode == 'r') && stk_a->len >= 2)
		rotate(stk_a);
	if ((mode == 'b' || mode == 'r') && stk_b->len >= 2)
		rotate(stk_b);
	update_stack_data(stk_a, stk_b);
	ft_printf("r%c\n", mode);
}
