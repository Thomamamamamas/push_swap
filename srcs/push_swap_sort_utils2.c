/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 17:43:42 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.c"

int	*get_chunk(t_stk *a, int *hold, int len)
{
	int	*chunk;
	int	chunk_len;
	int	n;
	int	m;

	chunk = (int *)malloc(sizeof(int) * 21);
	chunk_len = 0;
	n = 0;
	m = 0;
	while (n < len)
	{
		if (!is_in_array(a->stk[n], hold, len))
		{
			if (chunk_len <= 20)
			{
				chunk[m++] = a->stk[n];
				chunk_len++;
			}
			else if (get_index_of_larger_nb(a->stk[n], hold, len))
			{
				chunk[get_index_of_larger_nb(a->stk[n], hold, len)] = a->stk[n];
				chunk_len++;
			}
		}
		n++;
	}
	return (chunk);
}

int	
