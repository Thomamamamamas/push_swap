/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:31:34 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/05 22:10:18 by tcasale          ###   ########.fr       */
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

int	is_in_lst(int n, t_lst *lst)
{
	int	m;

	m = 0;
	while (m < lst->len)
	{
		if (n == lst->lst[m])
			return (1);
		m++;
	}
	return (0);
}

int	get_index_of_larger_nb(int nb, t_lst *lst)
{
	int	n;
	int	max;
	int	res;

	n = 0;
	max = INT_MIN;
	res = -1;
	while (n < lst->len)
	{
		if (lst->lst[n] > max)
		{
			max = lst->lst[n];
			res = n;
		}
		n++;
	}
	if (max > nb)
		return (res);
	return (-1);
}

void	append_lst(int nb, t_lst *lst)
{
	int	*tmp;
	int	n;

	tmp = (int *)malloc(sizeof(int) * lst->len);
	n = 0;
	while (n < lst->len)
	{
		tmp[n] = lst->lst[n];
		n++;
	}
	free(lst->lst);
	lst->lst = (int *)malloc(sizeof(int) * ++lst->len);
	n = 0;
	while (n < lst->len - 1)
	{
		lst->lst[n] = tmp[n];
		n++;
	}
	lst->lst[n] = nb;
	free(tmp);
}
