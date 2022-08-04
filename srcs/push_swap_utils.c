/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:40:28 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 15:54:35 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	init_stack(t_stk *a, t_stk *b)
{
	b->len = 0;
	b->stk = (int *)malloc(sizeof(int) * a->len);
}

int	stack_is_sort(t_stk *stk)
{
	int	i;
	int	j;

	i = stk->len - 1;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stk->stk[j] < stk->stk[i])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}
