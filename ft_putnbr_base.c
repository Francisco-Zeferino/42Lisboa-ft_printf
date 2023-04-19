/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:07:52 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/18 15:50:09 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_num(char c)
{
	write(1, &c, 1);
}

static int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	len;
	int	buff;

	buff = 1;
	len = check_len(base);
	if (nbr == -2147483648)
	{
		print_num('-');
		buff += ft_putnbr_base(2, base);
		nbr = 147483648;
		buff++;
	}
	else if (nbr < 0)
	{
		print_num('-');
		nbr *= -1;
		buff++;
	}
	if (nbr >= len)
		buff += ft_putnbr_base(nbr / len, base);
	print_num(base[nbr % len]);
	return (buff);
}
