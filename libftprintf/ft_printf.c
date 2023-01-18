/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:58:45 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/02 12:28:46 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_int(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr_int(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printaddress(va_arg(args, long unsigned), "0123456789abcdef");
	else if (c == 'd')
		len += ft_putnbrbase_int(va_arg(args, int), "0123456789");
	else if (c == 'i')
		len += ft_putnbrbase_int(va_arg(args, int), "0123456789");
	else if (c == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_puthex_int(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_puthex_int(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
	{
		write(1, "%", 1);
		len += 1;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print;

	va_start(args, str);
	i = 0;
	print = 0;
	if (!str || str == NULL)
		return (ft_putstr_int("(null)"));
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print += ft_check(str[i], args);
		}
		else
		{
			ft_putchar_int(str[i]);
			print += 1;
		}
		i++;
	}
	va_end(args);
	return (print);
}
