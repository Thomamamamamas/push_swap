/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:33:00 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/28 13:02:44 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

char	*do_conversion(va_list arguments, t_ptfo *po)
{
	if (po->conv == 'd' || po->conv == 'i')
		return (ft_itoa(va_arg(arguments, int)));
	else if (po->conv == 's')
		return (ft_strdup(va_arg(arguments, char *)));
	else if (po->conv == 'p')
		return (ft_itoa_adress(va_arg(arguments, unsigned long long)));
	else if (po->conv == 'x')
		return (ft_itoa_base(va_arg(arguments, unsigned int), 16));
	else if (po->conv == 'X')
		return (ft_itoa_base(va_arg(arguments, unsigned int), 16));
	else if (po->conv == 'u')
		return (ft_itoa_unsigned(va_arg(arguments, int)));
	return (NULL);
}

int	conversion_is_number(int conversion)
{
	if (conversion == 'd' || conversion == 'i' || conversion == 'u')
		return (1);
	else if (conversion == 'x' || conversion == 'X')
		return (1);
	return (0);
}
