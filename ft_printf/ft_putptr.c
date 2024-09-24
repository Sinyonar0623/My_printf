/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:46:02 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/22 13:25:49 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long int tmp, int l)
{
	char	*hex;
	int		len;

	if (tmp == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	len = l;
	if (tmp < 16)
	{
		len = l + ft_puts("0x");
		len += ft_putchar(hex[tmp]);
	}
	else
	{
		len = l + ft_putptr(tmp / 16, len);
		len += ft_putchar(hex[tmp % 16]);
	}
	return (len);
}

int	ft_itoh_l(unsigned long long int tmp, int l)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = l;
	if (tmp < 16)
		len = l + ft_putchar(hex[tmp]);
	else
	{
		len = l + ft_itoh_l(tmp / 16, len);
		len += ft_putchar(hex[tmp % 16]);
	}
	return (len);
}

int	ft_itoh_u(unsigned long long int tmp, int l)
{
	int		len;
	char	*hex;

	hex = "0123456789ABCDEF";
	len = l;
	if (tmp < 16)
		len = l + ft_putchar(hex[tmp]);
	else
	{
		len = l + ft_itoh_u(tmp / 16, len);
		len += ft_putchar(hex[tmp % 16]);
	}
	return (len);
}
