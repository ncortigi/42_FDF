/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:25:48 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/02 12:50:17 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbrbase_int(int nbr, char *base)
{
	int		lbase;
	int		i;
	int		ret;
	int		arr_n[32];
	long	n;

	n = nbr;
	lbase = count_base(base);
	i = 0;
	ret = 0;
	if (n == 0)
		return (ft_putstr_int("0"));
	if (n < 0)
	{
		ret += ft_putchar_int(45);
		n = -n;
	}
	while (n)
	{
		arr_n[i++] = n % lbase;
		n = n / lbase;
	}
	while (--i >= 0)
		ret += ft_putchar_int(base[arr_n[i]]);
	return (ret);
}
