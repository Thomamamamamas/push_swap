/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:29:53 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/05 21:46:05 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	print_stacks(t_stk *stk_a, t_stk *stk_b)
{
	int	n;

	if (stk_a->len > stk_b->len)
		n = stk_a->len - 1;
	else
		n = stk_b->len - 1;
	while (n >= 0)
	{
		if (n >= stk_a->len)
			ft_printf("| ");
		else
			ft_printf("|%d", stk_a->stk[n]);
		ft_printf("          ");
		if (n >= stk_b->len)
			ft_printf("| \n");
		else
			ft_printf("|%d\n", stk_b->stk[n]);
		n--;
	}
	ft_printf("|-----------|-------\n|stk_a    |stk_b\n");
}

void	print_chunk(t_chunk *chunk)
{
	int	n;
	
	n = 0;
	ft_printf("_______________\n");
	while (n < chunk->chunk.len)
	{
		ft_printf("%d\n", chunk->chunk.lst[n]);
		n++;
	}
	ft_printf("_____CHUNK_____\n");
	ft_printf("chunk len = %d\n", chunk->chunk.len);
}
