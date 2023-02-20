/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:02:29 by malema            #+#    #+#             */
/*   Updated: 2023/01/19 15:03:44 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printchar(int c);
int		ft_putstr_fd(char *s);
int		check_arg(va_list myargs, char identifier);
int		ft_printf(const char *s, ...);
char	*ft_itoa(int c);
int		ft_printnum(int n);
int		ft_printhexa(unsigned int hex, char c);
int		ft_printptr(unsigned long long p);
int		ft_printunum(unsigned int num);

#endif