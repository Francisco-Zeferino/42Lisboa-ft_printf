/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:04:00 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/19 11:07:36 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_num(char c)
{
	write(1, &c, 1);
}

static int	check_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nbr, char *base)
{
	unsigned int	len;
	int				buff;

	buff = 1;
	len = check_len(base);
	if (nbr >= len)
		buff += ft_putnbr_base(nbr / len, base);
	print_num(base[nbr % len]);
	return (buff);
}
