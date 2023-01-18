/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:10:49 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/02 12:52:47 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_int(unsigned int n, char *base)
{
	int	arr_n[32];
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (n == 0)
		return (ft_putstr_int("0"));
	while (n)
	{
		arr_n[i++] = n % 16;
		n = n / 16;
	}
	while (--i >= 0)
		ret += ft_putchar_int(base[arr_n[i]]);
	return (ret);
}
