/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:57:51 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/07 15:11:01 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	sum;

	sum = nmemb * size;
	if (nmemb * size == 0)
		sum = sum + 1;
	alloc = malloc(sum);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, sum);
	return (alloc);
}
