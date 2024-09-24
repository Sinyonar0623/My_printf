/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:59:02 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/22 17:06:14 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int l)
{
	int		len;
	long	ln;

	len = l;
	ln = nbr;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		ln *= -1;
	}
	if (ln < 10)
		len += ft_putchar(ln + '0');
	else
	{
		len = ft_putnbr(ln / 10, len);
		len += ft_putchar((ln % 10) + '0');
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned long long int nbr, int l)
{
	int		len;

	len = l;
	if (nbr < 10)
		len += ft_putchar(nbr + '0');
	else
	{
		len = ft_putnbr_unsigned(nbr / 10, len);
		len += ft_putchar((nbr % 10) + '0');
	}
	return (len);
}
