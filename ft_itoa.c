/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:44:40 by malema            #+#    #+#             */
/*   Updated: 2023/01/13 14:11:34 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

int	nbr_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (++count);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_check(int n)
{
	if (n < 0)
		return (nbr_len(n) + 1);
	else
		return (nbr_len(n));
}

char	*ft_itoa(int c)
{
	int		size;
	char	*str;
	long	n;

	n = c;
	size = ft_check(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[size - 1] = 48 + (n % 10);
		n = n / 10;
		size--;
	}
	return (str);
}
