/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:09:21 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/04/19 11:07:20 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr_base(long long nbr, char *base);
int	ft_putnbr_unsigned(unsigned int nbr, char *base);
int	ft_putstr(char *str);
int	ft_printf(const char *input, ...);
int	ft_strlen(const char *str);
int	ft_printadr(unsigned long long ptr, char *base);

#endif
