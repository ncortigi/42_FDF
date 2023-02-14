/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:18:33 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/12 15:29:47 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_array(int nb, int fd)
{
	int	array[10];
	int	i;

	i = 0;
	while (nb >= 10)
	{
		array[i] = nb % 10;
		nb /= 10;
		i++;
	}
	if (nb < 10)
		array[i] = nb % 10;
	while (i >= 0)
	{
		ft_putchar_fd(array[i] + 48, fd);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(45, fd);
			n = -n;
		}
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else if (n >= 10)
			print_array(n, fd);
	}
}
