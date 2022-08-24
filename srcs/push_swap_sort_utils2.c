/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/24 22:17:39 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

t_chunk	get_chunk(t_stk *a, t_lst *hold)
{
	t_chunk	chunk;
	int		n;

	chunk.chunk.lst = (int *)malloc(sizeof(int) * 21);
	chunk.position = (int *)malloc(sizeof(int) * 21);
	chunk.chunk.len = 0;
	n = 0;
	while (n < a->len)
	{
		if (!is_in_lst(a->stk[n], hold))
		{
			if (chunk.chunk.len < 20)
			{
				chunk.chunk.lst[chunk.chunk.len] = a->stk[n];
				chunk.position[chunk.chunk.len] = n;
				chunk.chunk.len++;
			}
			else if (get_index_of_larger_nb(a->stk[n], &chunk.chunk) != -1)
			{
				chunk.position[get_index_of_larger_nb(a->stk[n], &chunk.chunk)] = n;
				chunk.chunk.lst[get_index_of_larger_nb(a->stk[n], &chunk.chunk)] = a->stk[n];
			}
		}
		n++;
	}
	return (chunk);
}

void	smart_rotate(t_stk *a, t_stk *b, int position)
{
	while (position < a->len - 1)
	{
		if (position <= a->len / 2)
		{
			stack_reverse_rotate(a, b, 'a');
			position--;
			if (position < 0)
				position = a->len - 1;
		}
		else
		{
			stack_rotate(a, b, 'a');
			position++;
		}
	}
}
