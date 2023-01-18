/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:51:37 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/12 17:35:59 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_par(char *str, char tofind)
{
	int	found;
	int	count;
	int	i;

	i = 0;
	count = 0;
	found = 0;
	if (str[0] != '\0')
	{
		while (str[i])
		{
			if (found == 0 && str[i] != tofind)
			{
				count++;
				found = 1;
			}
			else if (found == 1 && str[i] == tofind)
				found = 0;
			i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		parole;
	int		i;
	int		len_par;
	char	**matrix;

	parole = count_par((char *)s, c);
	matrix = (char **)ft_calloc((parole + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len_par = ft_strlen(s);
			else
				len_par = ft_strchr(s, c) - s;
			matrix[i++] = ft_substr(s, 0, len_par);
			s += len_par;
		}
	}
	return (matrix);
}
