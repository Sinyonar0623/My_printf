/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:00:32 by ctharawi          #+#    #+#             */
/*   Updated: 2024/09/22 13:25:11 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_printed
{
	int			byte;
	const char	*str;
	va_list		argc;
}	t_bytprt;

int	ft_printf(const char *ptr, ...);
int	ft_putchar(int c);
int	ft_puts(const char *s);
int	ft_putptr(unsigned long int tmp, int l);
int	ft_putnbr(int nbr, int l);
int	ft_putnbr_unsigned(unsigned long long int nbr, int l);
int	ft_itoh_l(unsigned long long int tmp, int l);
int	ft_itoh_u(unsigned long long int tmp, int l);

#endif
