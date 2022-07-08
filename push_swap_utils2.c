/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:31:34 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/08 17:37:02 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
