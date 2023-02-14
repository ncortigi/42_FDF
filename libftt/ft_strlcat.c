/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:48:28 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/06 11:58:03 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	j = dest_len;
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + i) < size)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if ((dest_len + i) == size && dest_len < size)
		dest[--j] = '\0';
	else
		dest[j] = '\0';
	return (src_len + dest_len);
}
