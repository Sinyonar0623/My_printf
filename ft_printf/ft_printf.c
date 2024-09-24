/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:49:49 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/22 15:10:46 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_conversions(const char *str, va_list argc)
{
	size_t	len;

	len = 0;
	if (*str == 'c')
		len = ft_putchar(va_arg(argc, int));
	else if (*str == 's')
		len = ft_puts(va_arg(argc, const char *));
	else if (*str == 'p')
		len = ft_putptr(va_arg(argc, unsigned long), 0);
	else if (*str == 'd' || *str == 'i')
		len = ft_putnbr(va_arg(argc, int), 0);
	else if (*str == 'u')
		len = ft_putnbr_unsigned(va_arg(argc, unsigned), 0);
	else if (*str == 'x')
		len = ft_itoh_l(va_arg(argc, unsigned int), 0);
	else if (*str == 'X')
		len = ft_itoh_u(va_arg(argc, unsigned int), 0);
	else if (*str == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *ptr, ...)
{
	t_bytprt	p;

	p.byte = 0;
	va_start(p.argc, ptr);
	p.str = ptr;
	while (*p.str != '\0')
	{
		if (*p.str == '%')
			p.byte += ft_conversions(++p.str, p.argc);
		else
		{
			write(1, p.str, 1);
			p.byte++;
		}
		p.str++;
	}
	return (p.byte);
}
