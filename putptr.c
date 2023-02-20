/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:01:10 by malema            #+#    #+#             */
/*   Updated: 2023/01/17 14:48:16 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter2(unsigned long long nb)
{
	int	count ;

	count = 0;
	while (nb != 0)
	{
		count++;
		nb = nb / 16;
	}
	return (count);
}

void	ft_writehex2(unsigned long long hex)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (hex >= 16)
	{
		ft_writehex2(hex / 16);
		ft_writehex2(hex % 16);
	}
	else
	{
		ft_printchar(arr[hex % 16]);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	c;

	c = 0;
	c = c + write(1, "0x", 2);
	if (ptr == 0)
		c = c + ft_printchar(48);
	else
	{
		ft_writehex2(ptr);
	}
	c += ft_counter2(ptr);
	return (c);
}
