/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:28:20 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/27 14:38:51 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || str == NULL)
		return (ft_putstr_int("(null)"));
	while (str[i])
	{
		count += ft_putchar_int(str[i]);
		i++;
	}
	return (count);
}
