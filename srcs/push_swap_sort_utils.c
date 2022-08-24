/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/24 22:18:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	mini_stack_empty_b(t_stk *a, t_stk *b)
{
	if (a->top < b->top || a->bottom > b->top || a->max < b->top)
	{
		if (a->max > b->top)
		{
			while (b->top < a->bottom && b->top > a->min)
				stack_reverse_rotate(a, b, 'a');
			while (b->top > a->top)
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			if (b->len == 0 || (b->len > 0 && b->top < a->min))
			{
				while (!stack_is_sort(a))
					stack_rotate(a, b, 'a');
			}
		}
		else
		{
			while (!stack_is_sort(a))
				stack_rotate(a, b, 'a');
			stack_push(a, b, 'a');
			stack_rotate(a, b, 'a');
		}
	}
	else
		stack_push(a, b, 'a');
}

void	medium_stack_empty_a(t_stk *a, t_stk *b)
{
	t_lst	hold;
	t_chunk	chunk;
	int		position;

	hold.len = 0;
	position = 0;
	while (a->len != 0)
	{
		chunk = get_chunk(a, &hold);
		print_chunk(&chunk);
		position = get_hold_position(a, &hold, &chunk);
		append_lst(a->stk[position], &hold);
		print_hold(&hold);
		ft_printf("position = %d\n", position);
		smart_rotate(a, b, position);
		//print_stacks(a, b);
		ft_printf("%d\n", a->stk[a->len -1]);
		stack_push(a, b, 'a');
		free(chunk.chunk.lst);
		free(chunk.position);
		return ;
	}
	free(hold.lst);
}

int	get_hold_position(t_stk *a, t_lst *hold, t_chunk *chunk)
{
	int	hold_top;
	int	hold_bottom;
	int	n;
	int	m;

	n = -1;
	m = a->len;
	hold_top = INT_MAX;
	hold_bottom = INT_MAX;
	while (n <= a->len / 2 && hold_top == INT_MAX)
	{
		n++;
		if (valide_hold(a->stk[n], hold, chunk))
			hold_top = a->stk[n];
	}
	while (m > a->len / 2 && hold_bottom == INT_MAX)
	{
		m--;
		if (valide_hold(a->stk[m], hold, chunk))
			hold_bottom = a->stk[m];
	}
	if (n <= a->len - m)
	{
		ft_printf("n\n");
		return (n);
	}
	else
	{
		ft_printf("m\n");
		return (m);
	}
}

int	valide_hold(int nb, t_lst *hold, t_chunk *chunk)
{
	int	n;

	n = 0;
	while (n < hold->len)
	{
		if (nb == hold->lst[n])
			return (0);
		n++;
	}
	n = 0;
	while (n < chunk->chunk.len)
	{
		if (nb == chunk->chunk.lst[n])
			return (1);
		n++;
	}
	return (0);
}
