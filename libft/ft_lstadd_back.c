/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:41:38 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/13 10:44:14 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
