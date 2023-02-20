/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:27 by malema            #+#    #+#             */
/*   Updated: 2023/01/17 15:20:06 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check_arg(va_list ar, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(ar, int));
	else if (c == 's')
		count += ft_putstr_fd(va_arg(ar, char *));
	else if (c == 'd' || c == 'i')
		count += ft_printnum(va_arg(ar, int));
	else if (c == 'p')
		count += ft_printptr(va_arg(ar, unsigned long long));
	else if (c == 'u')
		count += ft_printunum(va_arg(ar, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_printhexa(va_arg(ar, unsigned int), c);
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	myargs;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(myargs, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = count + check_arg(myargs, s[i + 1]);
			i++;
		}
		else
		{
			count = count + ft_printchar(s[i]);
		}
		i++;
	}
	va_end(myargs);
	return (count);
}
