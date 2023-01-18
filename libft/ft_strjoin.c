/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:05:30 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/10 12:24:22 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		sum;
	int		i;
	int		j;

	sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * sum);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		str[j] = ((char *)s2)[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
