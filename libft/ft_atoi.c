/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:41:25 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/06 16:37:00 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_converter(const char *str)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while ((str[i] > 47 && str[i] < 58) && str[i])
	{
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (sum);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	meno;

	i = 0;
	meno = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
	{
		meno *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	return (ft_converter(&nptr[i]) * meno);
}
