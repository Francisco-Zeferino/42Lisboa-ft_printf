/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:27:13 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/19 11:12:22 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_type(char d_type, va_list arg)
{
	if (d_type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (d_type == 'd' || d_type == 'i')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789"));
	else if (d_type == 'x')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int),
				"0123456789abcdef"));
	else if (d_type == 'X')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int),
				"0123456789ABCDEF"));
	else if (d_type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (d_type == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int), "0123456789"));
	else if (d_type == 'p')
		return (ft_printadr(va_arg(arg, unsigned long long),
				"0123456789abcdef"));
	else if (d_type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += get_type(input[i + 1], arg);
			i++;
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
