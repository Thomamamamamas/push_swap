/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:21:24 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:31:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	stack_swap(t_stk *a, t_stk *b, int mode)
{
	int	tmp;

	if ((mode == 'a' || mode == 's') && a->len >= 2)
	{
		tmp = a->stk[a->len - 1];
		a->stk[a->len - 1] = a->stk[a->len - 2];
		a->stk[a->len - 2] = tmp;
	}
	if ((mode == 'b' || mode == 's') && b->len >= 2)
	{
		tmp = b->stk[b->len - 1];
		b->stk[b->len - 1] = b->stk[b->len - 2];
		b->stk[b->len - 2] = tmp;
	}
	update_stack_data(a, b);
	ft_printf("s%c\n", mode);
}

void	stack_push(t_stk *a, t_stk *b, int mode)
{
	if (mode == 'a' && b->len >= 1)
		a->stk[a->len++] = b->stk[--b->len];
	else if (mode == 'b' && a->len >= 1)
		b->stk[b->len++] = a->stk[--a->len];
	update_stack_data(a, b);
	ft_printf("p%c\n", mode);
}

void	stack_reverse_rotate(t_stk *a, t_stk *b, int mode)
{
	if ((mode == 'a' || mode == 'r') && a->len >= 2)
	{
		reverse_rotate(a);
	}
	if ((mode == 'b' || mode == 'r') && b->len >= 2)
		reverse_rotate(b);
	update_stack_data(a, b);
	ft_printf("rr%c\n", mode);
}

void	stack_rotate(t_stk *a, t_stk *b, int mode)
{
	if ((mode == 'a' || mode == 'r') && a->len >= 2)
		rotate(a);
	if ((mode == 'b' || mode == 'r') && b->len >= 2)
		rotate(b);
	update_stack_data(a, b);
	ft_printf("r%c\n", mode);
}
