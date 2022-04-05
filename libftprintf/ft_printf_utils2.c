/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:57:43 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/28 12:56:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*negative_str_to_positive(char *str, t_ptfo *po)
{
	int	tmp;

	tmp = ft_atoi(str) * -1;
	if (str)
		free(str);
	str = ft_itoa(tmp);
	if (tmp > 0)
		po->len += ft_putchar('-');
	return (str);
}

int	is_flag(char content)
{
	if (content == '+')
		return (1);
	else if (content == ' ')
		return (1);
	else if (content == '.')
		return (1);
	else if (content == '#')
		return (1);
	return (0);
}
