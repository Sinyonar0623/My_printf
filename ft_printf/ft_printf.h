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

/*
** Structure to manage printf state
** byte: count of characters printed
** str: current position in format string
** argc: variable arguments list
*/
typedef struct s_printed
{
	int			byte;
	const char	*str;
	va_list		argc;
}	t_bytprt;

/*
** Main printf function - mimics standard printf behavior
** Supports: %c %s %p %d %i %u %x %X %%
** Returns: number of characters printed
*/
int	ft_printf(const char *ptr, ...);

/*
** Character output function
** Returns: always 1 (number of characters printed)
*/
int	ft_putchar(int c);

/*
** String output function - handles NULL strings
** Returns: number of characters printed
*/
int	ft_puts(const char *s);

/*
** Pointer output function - prints address in hex with "0x" prefix
** Handles NULL pointers by printing "(nil)"
** Returns: number of characters printed
*/
int	ft_putptr(unsigned long int tmp, int l);

/*
** Signed integer output function (recursive implementation)
** Handles negative numbers with sign display
** Returns: number of characters printed
*/
int	ft_putnbr(int nbr, int l);

/*
** Unsigned integer output function (recursive implementation)
** Returns: number of characters printed
*/
int	ft_putnbr_unsigned(unsigned long long int nbr, int l);

/*
** Lowercase hexadecimal output function (recursive implementation)
** Uses characters 0-9, a-f
** Returns: number of characters printed
*/
int	ft_itoh_l(unsigned long long int tmp, int l);

/*
** Uppercase hexadecimal output function (recursive implementation)
** Uses characters 0-9, A-F
** Returns: number of characters printed
*/
int	ft_itoh_u(unsigned long long int tmp, int l);

#endif
