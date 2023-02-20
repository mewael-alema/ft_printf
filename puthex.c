/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:01:02 by malema            #+#    #+#             */
/*   Updated: 2023/01/17 18:04:21 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter(unsigned int nb)
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

void	ft_writehex(unsigned int hex, char c)
{
	char	*arr;
	char	*arr2;

	arr = "0123456789abcdef";
	arr2 = "0123456789ABCDEF";
	if (hex >= 16)
	{
		ft_writehex(hex / 16, c);
		ft_writehex(hex % 16, c);
	}
	else
	{	
		if (c == 'x')
			ft_printchar(arr[hex % 16]);
		else
			ft_printchar(arr2[hex % 16]);
	}
}

int	ft_printhexa(unsigned int hex, char c)
{
	int	count;

	count = 0;
	if (hex == 0)
		count = count + ft_printchar(48);
	else
	{
		ft_writehex(hex, c);
		count += ft_counter(hex);
	}
	return (count);
}
