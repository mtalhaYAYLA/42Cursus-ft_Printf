/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:22:54 by myayla            #+#    #+#             */
/*   Updated: 2022/12/07 10:47:25 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int w)
{
	int	len;

	len = 0;
	if (w == 0)
		return (write(1, "0", 1));
	if (w == -2147483648)
		return (write(1, "-2147483648", 11));
	if (w < 0)
	{
		len += write(1, "-", 1);
		w *= -1;
	}
	if (w >= 10)
		len += ft_int(w / 10);
	write(1, &"0123456789"[w % 10], 1);
	return (len + 1);
}

int	ft_unsigned(unsigned int w)
{
	int	len;

	len = 0;
	if (w >= 10)
		len += ft_unsigned(w / 10);
	write(1, &"0123456789"[w % 10], 1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_hex(unsigned int d, char w)
{
	int	len;

	len = 0;
	if (d >= 16)
		len += ft_hex(d / 16, w);
	if (w == 'X')
		write(1, &"0123456789ABCDEF"[d % 16], 1);
	if (w == 'x')
		write(1, &"0123456789abcdef"[d % 16], 1);
	return (len + 1);
}

int	ft_point(unsigned long w, int i)
{
	int	len;

	len = 0;
	if (i == 1)
	{
		len += write(1, "0x", 2);
		i = 0;
	}
	if (w >= 16)
		len += ft_point(w / 16, i);
	write(1, &"0123456789abcdef"[w % 16], 1);
	return (len + 1);
}
