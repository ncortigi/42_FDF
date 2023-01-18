/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:29:01 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/21 15:01:43 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_cifre(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	numero;
	size_t	len_num;

	numero = n;
	len_num = count_cifre(numero);
	str = malloc(sizeof(char) * (len_num + 1));
	if (!str)
		return (NULL);
	str[len_num] = '\0';
	if (numero < 0)
	{
		str[0] = '-';
		numero *= -1;
	}
	if (numero == 0)
		str[0] = '0';
	len_num--;
	while (numero)
	{
		str[len_num] = numero % 10 + 48;
		numero = numero / 10;
		len_num--;
	}
	return (str);
}
