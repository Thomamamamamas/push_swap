/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/05 22:05:25 by tcasale          ###   ########.fr       */
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
	while (a->len != 0)
	{
		ft_printf("a\n");
		chunk = get_chunk(a, &hold);
		ft_printf("b\n");
		print_chunk(&chunk);
		position = get_hold_position(a, &hold, &chunk);
		add_to_hold_lst(position, &hold, &chunk);
		ft_printf("c\n");
		ft_printf("position = %d\n", position);
		//print_stacks(a, b);
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

	n = 0;
	m = 0;
	hold_top = INT_MAX;
	hold_bottom = INT_MAX;
	while (n <= a->len / 2)
	{
		if (valide_hold(a->stk[n], hold, chunk) && a->stk[n] < hold_top)
			hold_top = a->stk[n];
		n++;
	}
	while (m > a->len / 2)
	{
		if (valide_hold(a->stk[n], hold, chunk) && a->stk[n] < hold_bottom)
			hold_top = a->stk[n];
		m++;
	}
	if (n < m)
		return (n);
	else
		return (m);
}

int	valide_hold(int nb, t_lst *hold, t_chunk *chunk)
{
	int	n;
	int	m;

	n = 0;
	while (n < hold->len)
	{
		if (nb == hold->lst[n])
			return (0);
		n++;
	}
	n = 0;
	while (n < hold->len)
	{
		m = 0;
		while (m < chunk->chunk.len)
		{
			if (hold->lst[n] == chunk->chunk.lst[m])
				return (1);
			m++;
		}
		n++;
	}
	return (0);
}

void	add_to_hold_lst(int position, t_lst *hold, t_chunk *chunk)
{
	int	n;

	n = 0;
	while (n < chunk->chunk.len)
	{
		if (chunk->position[n] == position)
			append_lst(chunk->chunk.lst[n], hold);
		n++;
	}
}
