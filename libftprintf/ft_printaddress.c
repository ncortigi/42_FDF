/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:57:43 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/02 12:47:46 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(long unsigned n, char *base)
{
	int	arr_n[32];
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (n == 0)
		return (ft_putstr_int("(nil)"));
	ret += ft_putstr_int("0x");
	while (n)
	{
		arr_n[i++] = n % 16;
		n = n / 16;
	}
	while (--i >= 0)
		ret += ft_putchar_int(base[arr_n[i]]);
	return (ret);
}
