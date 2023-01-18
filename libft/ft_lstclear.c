/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:53:06 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/13 11:01:33 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lista;
	t_list	*nodo;

	if (!lst)
		return ;
	lista = *lst;
	nodo = NULL;
	while (lista)
	{
		nodo = lista;
		lista = lista->next;
		del(nodo->content);
		free(nodo);
	}
	*lst = NULL;
}
