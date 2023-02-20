/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:51:50 by malema            #+#    #+#             */
/*   Updated: 2023/01/17 14:54:57 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(unsigned int num)
{
	size_t	nsize;

	nsize = 0;
	while (num != 0)
	{
		num = num / 10;
		nsize++;
	}
	return (nsize);
}

char	*ft_unumtostr(unsigned int num)
{
	char	*str;
	int		i;

	i = ft_numlen(num);
	str = (char *) malloc (sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (num != 0)
	{
		str[i - 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}

int	ft_printunum(unsigned int num)
{
	int		count;
	char	*s;

	count = 0;
	if (num == 0)
		return (ft_printchar('0'));
	s = ft_unumtostr(num);
	count = ft_putstr_fd(s);
	free(s);
	return (count);
}
