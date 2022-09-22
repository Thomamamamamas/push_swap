/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:23 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/22 11:18:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	medium_stack_empty_a(t_stk *a, t_stk *b)
{
	t_lst	hold;

	hold.len = 0;
	hold.lst = (int *)malloc(sizeof(int) * hold.len + 1);
	while (a->len != 0)
	{
		push_chunk_to_b(a, b, &hold);
	}
	free(hold.lst);
}

void	push_chunk_to_b(t_stk *a, t_stk *b, t_lst *hold)
{
	t_lst	chunk;
	int		position;
	int		n;

	chunk = get_chunk(a, hold);
	position = -1;
	n = chunk.len;
	while (n > 0)
	{
		position = get_hold_position(a, hold, &chunk);
		append_lst(a->stk[position], hold);
		smart_rotate(a, b, position);
		smart_push_to_b(a, b);
		n--;
	}
	free(chunk.lst);
}

int	get_hold_position(t_stk *a, t_lst *hold, t_lst *chunk)
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
		return (n);
	else
		return (m);
}

int	valide_hold(int nb, t_lst *hold, t_lst *chunk)
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
	while (n < chunk->len)
	{
		if (nb == chunk->lst[n])
			return (1);
		n++;
	}
	return (0);
}
