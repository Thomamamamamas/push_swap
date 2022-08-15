/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/05 22:09:57 by tcasale          ###   ########.fr       */
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
				ft_printf("pute\n");
				chunk.chunk.lst[get_index_of_larger_nb(a->stk[n], &chunk.chunk)] = a->stk[n];
			}
		}
		n++;
	}
	return (chunk);
}
