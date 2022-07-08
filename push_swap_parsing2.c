/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:09:06 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/08 17:31:15 by tcasale          ###   ########.fr       */
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
