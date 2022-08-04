/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:31:34 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/04 17:43:49 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

int	get_number_index(t_stk *stk, int nb)
{
	int	n;

	n = 0;
	while (stk->stk[n] != nb)
		n++;
	if (stk->stk[n] == nb)
		return (n);
	return (-1);
}

int	is_in_array(int n, int *array, int len)
{
	int	m;

	m = 0;
	while (m < len)
	{
		if (n == array[m])
			return (0);
		m++;
	}
	return (1);
}

int	get_index_of_larger_nb(int n, int *array, int len)
{
	int	m;

	m = -1;
	while (m < len)
	{
		if (n < array[m])
			res = m;
		m++;
	}
	return (res);
}
