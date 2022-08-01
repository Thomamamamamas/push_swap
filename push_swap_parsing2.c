/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:09:06 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/01 15:35:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	number_of_int_in_string(char *str)
{
	int	len;
	int	is_int;

	len = 0;
	is_int = 0;
	while (*str)
	{
		if (ft_isdigit(*str) && is_int == 0)
		{
			len++;
			is_int = 1;
		}
		if (!ft_isdigit(*str))
			is_int = 0;
		str++;
	}
	return (len);
}

void	update_stk_parsing(t_stk *stk, int *numbers, int len)
{
	int	*tmp;
	int	n;
	int	m;
	
	tmp = (int *)malloc(sizeof(int) * stk->len);
	n = stk->len - 1;
	m = 0;
	while (n >= 0)
		tmp[m++] = stk->stk[n--];
	free(stk->stk);
	stk->len = stk->len + len;
	stk->stk = (int *)malloc(sizeof(int) * stk->len);
	n = m - 1;
	m = 0;
	while (n >= 0)
		stk->stk[m++] = tmp[n--];
	n = 0;
	while (m < stk->len)
		stk->stk[m++] = numbers[n++];
	free(tmp);
}

void	update_int_parsing(t_stk *stk)
{
	int	*tmp;
	int	m;

	tmp = (int *)malloc(sizeof(int) * stk->len);
	m = 0;
	while (m < stk->len)
	{
		tmp[m] = stk->stk[m];
		m++;
	}
	free(stk->stk);
	stk->len = stk->len + 1;
	stk->stk = (int *)malloc(sizeof(int) * stk->len);
	m = 0;
	while (m < stk->len)
	{
		stk->stk[m] = tmp[m];
		m++;
	}
	free(tmp);
}

int	check_if_negative_int_is_valid(char *str)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (n < ft_strlen(str))
	{
		m = 0;
		if (str[n] == '-')
		{
			n++;
			while (str[n] && ft_isdigit(str[n]))
			{
				n++;
				m++;
			}
			if (str[n])
			{
				if (str[n] != ' ' || m == 0)
					return (0);
			}
			else if (!str[n])
				if ((!ft_isdigit(str[n - 1]) && str[n - 1] != ' ') || m == 0)
					return (0);
		}
		n++;
	}
	return (1);
}
