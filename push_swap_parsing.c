/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:08:54 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/09 09:43:52 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	parse_stack(int argc, char **argv, t_stk *stk_a)
{
	int		n;
	int		m;

	if (arg_is_string_of_int(argv[argc - 1]))
	{
		stk_a->len = number_of_int_in_string(argv[argc - 1]);
		stk_a->stk = (int *)malloc(sizeof(int) * stk_a->len);
		parse_string(argv[argc - 1], stk_a);
	}
	else
	{
		stk_a->len = argc - 1;
		stk_a->stk = (int *)malloc(sizeof(int) * stk_a->len);
		n = stk_a->len;
		m = 0;
		while (n > 0)
		{
			if (arg_is_valid(argv[n]))
				stk_a->stk[m++] = ft_atoi(argv[n]);
			else
				handle_parsing_error(stk_a);
			n--;
		}
	}
}

int	arg_is_valid(char *argv)
{
	if (ft_strlen(argv) >= 10 && ft_atoi(argv) == 0)
		return (0);
	while (*argv)
	{
		if (!ft_isdigit(*argv) && *argv != '-')
			return (0);
		argv++;
	}
	return (1);
}

int	arg_is_string_of_int(char *argv)
{
	int	is_int;

	is_int = 0;
	while (*argv)
	{
		if (ft_isdigit(*argv) || *argv == ' ')
		{
			argv++;
			if (ft_isdigit(*argv) || *argv == ' ')
			{
				is_int = 1;
				argv++;
			}
		}
		else
			return (0);
	}
	if (is_int == 1)
		return (1);
	else
		return (0);
}

void	parse_string(char *argv, t_stk *stk_a)
{
	int		n;
	int		m;
	char	*tmp;

	m = 0;
	n = stk_a->len - 1;
	while (*argv)
	{
		if (ft_isdigit(*argv) && m == 0)
			tmp = (char *)malloc(sizeof(char) * 11);
		if (ft_isdigit(*argv))
			tmp[m++] = *argv;
		if (*argv == ' ')
		{
			stk_a->stk[n--] = ft_atoi(tmp);
			free(tmp);
			m = 0;
		}
		argv++;
	}
	if (tmp)
	{
		stk_a->stk[n--] = ft_atoi(tmp);
		free(tmp);
	}
}

void	handle_parsing_error(t_stk *stk_a)
{
	ft_printf("Error\n");
	free(stk_a->stk);
	exit(0);
}
