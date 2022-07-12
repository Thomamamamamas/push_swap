/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:08:54 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/12 21:45:49 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	parse_stack(int argc, char **argv, t_stk *stk_a)
{
	int		n;
	int		m;
	int *tmp;

	stk_a->len = 0;
	stk_a->stk = (int *)malloc(sizeof(int) * stk_a->len);
	n = argc - 1;
	m = 0;
	while (n > 0)
	{
		if (arg_is_string_of_int(argv[n]))
		{
			tmp = parse_string(argv[n]);
			update_str_parsing(stk_a, tmp, number_of_int_in_string(argv[n]));
			m = m + number_of_int_in_string(argv[n]);
			free(tmp);
		}
		else if (arg_is_valid(argv[n]))
		{
			update_int_parsing(stk_a);
			stk_a->stk[m++] = ft_atoi(argv[n]);
		}
		else
			handle_parsing_error(stk_a);
		n--;
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

int	*parse_string(char *argv)
{
	int		n;
	int		m;
	char	*tmp;
	int		*numbers;

	m = 0;
	n = number_of_int_in_string(argv) - 1;
	numbers = (int *)malloc(sizeof(int) * n);
	while (*argv)
	{
		if ((ft_isdigit(*argv) || *argv == '-') && m == 0 )
			tmp = (char *)malloc(sizeof(char) * 11);
		if (ft_isdigit(*argv) || *argv == '-')
			tmp[m++] = *argv;
		if (*argv == ' ' && m > 0)
		{
			numbers[n--] = ft_atoi(tmp);
			free(tmp);
			m = 0;
		}
		argv++;
	}
	if (tmp)
	{
		numbers[n--] = ft_atoi(tmp);
		free(tmp);
	}
	return (numbers);
}

void	handle_parsing_error(t_stk *stk_a)
{
	ft_printf("Error\n");
	free(stk_a->stk);
	exit(0);
}
