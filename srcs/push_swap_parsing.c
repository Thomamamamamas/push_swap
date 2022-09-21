/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:16:22 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/21 13:16:25 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/push_swap.h"

void	parsing(int argc, char **argv, t_stk *stk_a)
{
	int		n;
	int		m;
	char	**tmp;

	n = argc - 1;
	while (n > 0)
	{
		m = 0;
		tmp = ft_split(argv[n], ' ');
		while (tmp[m] != NULL)
		{
			if (char_is_valid(tmp[m]))
				update_stk_parse(stk_a, tmp[m]);
			else
				handle_parse_error(stk_a);
			m++;
		}
		n--;
	}
}

int	char_is_valid(char *str)
{
	if (ft_strlen(str) > 2 && ft_atoi(str) == 0)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-')
			return (0);
		if (*str == '-' && !str_is_negative(str))
			return (0);
		str++;
	}
	return (1);
}

int	str_is_negative(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (str[n] == '-')
		{
			n++;
			while (str[n])
			{
				if (str[n] == '-' || !ft_isdigit(str[n]))
					return (0);
				n++;
			}
			if (!str[n] && !ft_isdigit(str[n - 1]))
				return (0);
		}
		n++;
	}
	return (1);
}

void	update_stk_parse(t_stk *stk, char *str)
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
	stk->len++;
	stk->stk = (int *)malloc(sizeof(int) * stk->len - 1);
	n = m - 1;
	m = 0;
	while (n >= 0)
		stk->stk[m++] = tmp[n--];
	stk->stk[m] = ft_atoi(str);
	free(tmp);
}

void	handle_parse_error(t_stk *stk_a)
{
	ft_putstr_fd("Error\n", 2);
	free(stk_a->stk);
	exit(0);
}
