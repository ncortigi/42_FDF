/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:58:26 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/12 14:45:23 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i])
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
