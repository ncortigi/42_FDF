/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:46:05 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/02 12:51:42 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n, char *base)
{
	int		i;
	int		ret;
	int		arr_n[32];

	i = 0;
	ret = 0;
	if (n == 0)
		return (ft_putstr_int("0"));
	while (n)
	{
		arr_n[i++] = n % 10;
		n = n / 10;
	}
	while (--i >= 0)
		ret += ft_putchar_int(base[arr_n[i]]);
	return (ret);
}
