/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:13:57 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/07 16:24:51 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex(char c)
{
	char	*BASE;
	char	*base;
	int		i;

	i = 0;
	BASE = "0123456789ABCDEF";
	base = "0123456789abcdef";
	while (base[i])
	{
		if (c == '0')
			return (0);
		if (base[i] == c)
			return (i);
		else if (BASE[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_hex(char *str)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	while (str[i])
	{
		result = result * 16 + ft_hex(str[i]);
		i++;
	}
	return (result);
}
