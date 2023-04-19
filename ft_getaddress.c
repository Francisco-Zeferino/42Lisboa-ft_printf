/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:04:22 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/19 11:07:02 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_num(char c)
{
	write(1, &c, 1);
}

static size_t	check_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_printadr(unsigned long long ptr, char *base)
{
	size_t	len;
	int		buff;

	buff = 1;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = check_len(base);
	buff += write(1, "0x", 2);
	if (ptr >= len)
		buff += ft_putnbr_base(ptr / len, base);
	print_num(base[ptr % len]);
	return (buff);
}
