/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:53:02 by tcasale           #+#    #+#             */
/*   Updated: 2022/03/17 15:09:55 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	size_to_allocate(unsigned long long n)
{
	int	len;

	len = 0;
	while (n / 16 != 0)
	{
		n = n / 16;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_adress(unsigned long long n)
{
	char	*caracters;
	int		len;
	int		i;
	char	*str;

	len = size_to_allocate(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	caracters = "0123456789abcdef";
	str[len] = '\0';
	i = len - 1;
	while (n != 0)
	{
		str[i] = caracters[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}
