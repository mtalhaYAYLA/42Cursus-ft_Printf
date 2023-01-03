/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:10:07 by myayla            #+#    #+#             */
/*   Updated: 2022/12/07 12:30:01 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
		{
			len += ft_format(&args, str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_putchar(char x)
{
	return (write(1, &x, 1));
}

int	ft_format(va_list *args, char w)
{
	if (w == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (w == '%')
		return (ft_putchar('%'));
	else if (w == 'd' || w == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (w == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (w == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (w == 'X' || w == 'x')
		return (ft_hex(va_arg((*args), unsigned int), w));
	else if (w == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (0);
}
